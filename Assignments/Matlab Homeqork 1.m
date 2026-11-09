%
Sam Courtright
10/06/2026
This program calculates and plots projectile motion
%

clear; clc;

g = 9.81;
alpha = input('Enter the cannon angle in degrees: ' );
muzzle_velocity = input('Enter the speed the projectile leaves the launcher in meters/second: ');

%Flight time (s)
flight_time = (2 * muzzle_velocity * sind(alpha)) / g; 

%Max height
max_height = power(muzzle_velocity, 2) * ((power(sind(alpha), 2)) / (2 * g));


% Total horizontal distance
x_distance_m = power(muzzle_velocity, 2) * ((sind(2 * alpha)) / g);
meters_to_feet = 3.28084;
x_distance_ft = x_distance_m * meters_to_feet;

% Velocity
V_vertical = muzzle_velocity * sind(alpha);
V_horizontal = muzzle_velocity * cosd(alpha);
y_dist_vs_time = V_vertical * flight_time - (0.5 * g * power(flight_time, 2));
x_dist_vs_time = V_horizontal * flight_time;

% Output

fprintf('Input Trajectory Results\n');
fprintf('Flight Time (sec): %.2f\n', flight_time);
fprintf('Total Distance (m): %.2f\n', x_distance_m);
fprintf('Total Distance (ft) %.2f\n', x_distance_ft);
fprintf('Maximum Height (m): %.2f\n', max_height);
fprintf('Horizontal Velocity (m/s): %.2f\n', V_horizontal);
fprintf('Vertical Velocity (m/s): %.2f\n', V_vertical);

% Plotting

t = linspace(0, flight_time, 100);
x_traj = V_horizontal * t;
y_traj = (V_vertical * t) - (0.5 * g * (t.^2));

figure(1);
plot(x_traj, y_traj);
title('Projectile Height vs Distance');
xlabel('Distance (meters)');
ylabel('Height (meters)');

% 10 by 10 table setup
angles = linspace(5,85,10);
velocities = linspace(0,50,10);

distance_table = zeros(10,10);

for i = 1:10
    for j = 1:10
        ang = angles(i);
        v0 = velocities(j);
        distance_table(i,j) = (v0^2 * sind(2 * ang)) / g;
    end
end

% Display table
disp(round(distance_table, 2));

d_fixed = 30;
alpha_plot = linspace(5,85,100);
v_needed = sqrt((d_fixed * g) ./ sind(2 * alpha_plot));

figure(2);
plot(alpha_plot, v_needed);
title('Required Velocity vs Angle for Distance = 30m');
xlabel('Angle (degrees)');
ylabel('Velocity (m/s)');
ylim([0, 50]);