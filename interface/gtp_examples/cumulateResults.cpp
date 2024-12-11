/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <stdexcept>

using namespace std;

string overnight4 = "fuego-fuego-39.B+5.5.sgf fuego-fuego-4.W+34.5.sgf fuego-fuego-40.B+0.5.sgf fuego-fuego-6.B+1.5.sgf fuego-fuego-61.W+5.5.sgf fuego-fuego-67.B+0.5.sgf fuego-fuego-71.B+2.5.sgf fuego-fuego-75.B+2.5.sgf fuego-fuego-9.B+5.5.sgf fuego-gnugo-100.B+2.5.sgf fuego-gnugo-101.B+0.5.sgf fuego-gnugo-104.B+0.5.sgf fuego-gnugo-105.B+0.5.sgf fuego-gnugo-106.B+0.5.sgf fuego-gnugo-107.B+0.5.sgf fuego-gnugo-108.B+2.5.sgf fuego-gnugo-109.B+0.5.sgf fuego-gnugo-110.B+0.5.sgf fuego-gnugo-111.B+0.5.sgf fuego-gnugo-112.B+2.5.sgf fuego-gnugo-113.B+0.5.sgf fuego-gnugo-115.B+0.5.sgf fuego-gnugo-116.B+0.5.sgf fuego-gnugo-119.B+0.5.sgf fuego-gnugo-120.B+0.5.sgf fuego-gnugo-123.B+0.5.sgf fuego-gnugo-124.B+0.5.sgf fuego-gnugo-125.B+0.5.sgf fuego-gnugo-126.B+0.5.sgf fuego-gnugo-127.B+0.5.sgf fuego-gnugo-129.B+0.5.sgf fuego-gnugo-130.B+0.5.sgf fuego-gnugo-131.B+0.5.sgf fuego-gnugo-134.B+2.5.sgf fuego-gnugo-135.B+0.5.sgf fuego-gnugo-137.B+4.5.sgf fuego-gnugo-138.B+6.5.sgf fuego-gnugo-139.B+0.5.sgf fuego-gnugo-140.B+0.5.sgf fuego-gnugo-141.B+2.5.sgf fuego-gnugo-143.B+0.5.sgf fuego-gnugo-144.B+0.5.sgf fuego-gnugo-145.B+0.5.sgf fuego-gnugo-147.B+0.5.sgf fuego-gnugo-148.B+0.5.sgf fuego-gnugo-149.B+0.5.sgf fuego-gnugo-150.B+0.5.sgf fuego-gnugo-151.B+0.5.sgf fuego-gnugo-152.B+0.5.sgf fuego-gnugo-154.B+20.5.sgf fuego-gnugo-155.B+2.5.sgf fuego-gnugo-156.B+0.5.sgf fuego-gnugo-157.B+4.5.sgf fuego-gnugo-160.B+2.5.sgf fuego-gnugo-162.B+2.5.sgf fuego-gnugo-163.B+2.5.sgf fuego-gnugo-164.W+3.5.sgf fuego-gnugo-165.B+2.5.sgf fuego-gnugo-170.B+4.5.sgf fuego-gnugo-171.B+4.5.sgf fuego-gnugo-172.B+2.5.sgf fuego-gnugo-174.W+3.5.sgf fuego-gnugo-176.B+8.5.sgf fuego-gnugo-177.B+0.5.sgf fuego-gnugo-179.B+0.5.sgf fuego-gnugo-180.B+0.5.sgf fuego-gnugo-181.B+0.5.sgf fuego-gnugo-182.B+0.5.sgf fuego-gnugo-183.B+0.5.sgf fuego-gnugo-184.B+0.5.sgf fuego-gnugo-185.B+0.5.sgf fuego-gnugo-187.B+0.5.sgf fuego-gnugo-189.B+0.5.sgf fuego-gnugo-190.B+0.5.sgf fuego-gnugo-192.B+0.5.sgf fuego-gnugo-193.B+0.5.sgf fuego-gnugo-196.B+0.5.sgf fuego-gnugo-197.B+0.5.sgf fuego-gnugo-198.B+0.5.sgf fuego-gnugo-199.B+0.5.sgf gnugo-fuego-200.W+1.5.sgf gnugo-fuego-201.W+1.5.sgf gnugo-fuego-202.W+3.5.sgf gnugo-fuego-204.W+1.5.sgf gnugo-fuego-205.W+1.5.sgf gnugo-fuego-207.W+1.5.sgf gnugo-fuego-209.W+1.5.sgf gnugo-fuego-210.W+1.5.sgf gnugo-fuego-211.W+3.5.sgf gnugo-fuego-212.W+1.5.sgf gnugo-fuego-213.W+1.5.sgf gnugo-fuego-214.W+1.5.sgf gnugo-fuego-215.W+1.5.sgf gnugo-fuego-216.W+1.5.sgf gnugo-fuego-217.W+1.5.sgf gnugo-fuego-220.W+1.5.sgf gnugo-fuego-221.W+3.5.sgf gnugo-fuego-222.W+1.5.sgf gnugo-fuego-224.W+3.5.sgf gnugo-fuego-225.W+1.5.sgf gnugo-fuego-227.W+3.5.sgf gnugo-fuego-230.W+1.5.sgf gnugo-fuego-234.W+3.5.sgf gnugo-fuego-235.W+1.5.sgf gnugo-fuego-236.W+1.5.sgf gnugo-fuego-238.W+1.5.sgf gnugo-fuego-239.W+1.5.sgf gnugo-fuego-244.W+1.5.sgf gnugo-fuego-245.W+1.5.sgf gnugo-fuego-246.W+1.5.sgf gnugo-fuego-247.W+1.5.sgf gnugo-fuego-249.W+5.5.sgf gnugo-fuego-250.W+1.5.sgf gnugo-fuego-255.W+1.5.sgf gnugo-fuego-256.W+1.5.sgf gnugo-fuego-257.W+7.5.sgf gnugo-fuego-259.W+1.5.sgf gnugo-fuego-260.W+1.5.sgf gnugo-fuego-263.W+3.5.sgf gnugo-fuego-266.W+3.5.sgf gnugo-fuego-267.W+1.5.sgf gnugo-fuego-268.W+3.5.sgf gnugo-fuego-269.W+1.5.sgf gnugo-fuego-270.W+1.5.sgf gnugo-fuego-271.W+3.5.sgf gnugo-fuego-273.W+1.5.sgf gnugo-fuego-274.W+1.5.sgf gnugo-fuego-275.W+3.5.sgf gnugo-fuego-276.W+1.5.sgf gnugo-fuego-278.W+1.5.sgf gnugo-fuego-279.W+3.5.sgf gnugo-fuego-280.W+9.5.sgf gnugo-fuego-284.W+1.5.sgf gnugo-fuego-285.W+1.5.sgf gnugo-fuego-286.W+1.5.sgf gnugo-fuego-288.W+1.5.sgf gnugo-fuego-289.W+1.5.sgf gnugo-fuego-290.B+2.5.sgf gnugo-fuego-291.W+1.5.sgf gnugo-fuego-292.W+1.5.sgf gnugo-fuego-293.W+1.5.sgf gnugo-fuego-294.W+1.5.sgf gnugo-fuego-297.W+1.5.sgf gnugo-gnugo-300.W+21.5.sgf gnugo-gnugo-301.W+5.5.sgf gnugo-gnugo-302.W+3.5.sgf gnugo-gnugo-304.W+5.5.sgf gnugo-gnugo-305.W+17.5.sgf gnugo-gnugo-306.W+7.5.sgf gnugo-gnugo-307.W+1.5.sgf gnugo-gnugo-308.W+107.5.sgf gnugo-gnugo-309.B+34.5.sgf gnugo-gnugo-310.W+7.5.sgf gnugo-gnugo-311.W+19.5.sgf gnugo-gnugo-312.B+0.5.sgf gnugo-gnugo-313.W+9.5.sgf gnugo-gnugo-314.B+26.5.sgf gnugo-gnugo-315.B+14.5.sgf gnugo-gnugo-316.W+7.5.sgf gnugo-gnugo-317.W+15.5.sgf gnugo-gnugo-318.B+58.5.sgf gnugo-gnugo-319.B+38.5.sgf gnugo-gnugo-320.B+8.5.sgf gnugo-gnugo-321.W+35.5.sgf gnugo-gnugo-322.W+25.5.sgf gnugo-gnugo-323.W+23.5.sgf gnugo-gnugo-324.W+1.5.sgf gnugo-gnugo-325.W+13.5.sgf gnugo-gnugo-326.W+17.5.sgf gnugo-gnugo-327.B+68.5.sgf gnugo-gnugo-328.W+17.5.sgf gnugo-gnugo-329.W+21.5.sgf gnugo-gnugo-330.W+27.5.sgf gnugo-gnugo-331.W+7.5.sgf gnugo-gnugo-332.B+38.5.sgf gnugo-gnugo-333.B+0.5.sgf gnugo-gnugo-334.B+34.5.sgf gnugo-gnugo-335.B+26.5.sgf gnugo-gnugo-336.W+7.5.sgf gnugo-gnugo-337.B+48.5.sgf gnugo-gnugo-338.B+14.5.sgf gnugo-gnugo-340.W+11.5.sgf gnugo-gnugo-341.B+46.5.sgf gnugo-gnugo-342.B+4.5.sgf gnugo-gnugo-343.B+8.5.sgf gnugo-gnugo-344.W+5.5.sgf gnugo-gnugo-345.B+20.5.sgf gnugo-gnugo-346.B+8.5.sgf gnugo-gnugo-347.B+10.5.sgf gnugo-gnugo-348.W+47.5.sgf gnugo-gnugo-349.B+12.5.sgf gnugo-gnugo-350.W+9.5.sgf gnugo-gnugo-351.B+26.5.sgf gnugo-gnugo-352.B+12.5.sgf gnugo-gnugo-353.B+4.5.sgf gnugo-gnugo-354.W+11.5.sgf gnugo-gnugo-355.B+4.5.sgf gnugo-gnugo-356.W+11.5.sgf gnugo-gnugo-357.B+26.5.sgf gnugo-gnugo-358.W+7.5.sgf gnugo-gnugo-359.W+11.5.sgf gnugo-gnugo-360.B+0.5.sgf gnugo-gnugo-361.B+22.5.sgf gnugo-gnugo-362.B+10.5.sgf gnugo-gnugo-363.B+36.5.sgf gnugo-gnugo-364.W+27.5.sgf gnugo-gnugo-365.B+10.5.sgf gnugo-gnugo-366.W+27.5.sgf gnugo-gnugo-367.B+28.5.sgf gnugo-gnugo-368.W+27.5.sgf gnugo-gnugo-369.B+4.5.sgf gnugo-gnugo-370.W+13.5.sgf gnugo-gnugo-371.B+44.5.sgf gnugo-gnugo-372.W+7.5.sgf gnugo-gnugo-373.W+5.5.sgf gnugo-gnugo-374.W+3.5.sgf gnugo-gnugo-375.W+7.5.sgf gnugo-gnugo-376.B+20.5.sgf gnugo-gnugo-377.W+17.5.sgf gnugo-gnugo-378.W+5.5.sgf gnugo-gnugo-379.W+81.5.sgf gnugo-gnugo-380.B+2.5.sgf gnugo-gnugo-381.W+23.5.sgf gnugo-gnugo-382.B+4.5.sgf gnugo-gnugo-383.W+5.5.sgf gnugo-gnugo-384.B+18.5.sgf gnugo-gnugo-385.B+4.5.sgf gnugo-gnugo-386.W+7.5.sgf gnugo-gnugo-387.B+26.5.sgf gnugo-gnugo-388.B+14.5.sgf gnugo-gnugo-389.W+13.5.sgf gnugo-gnugo-390.B+8.5.sgf gnugo-gnugo-391.W+11.5.sgf gnugo-gnugo-392.W+17.5.sgf gnugo-gnugo-393.W+23.5.sgf gnugo-gnugo-394.B+12.5.sgf gnugo-gnugo-395.B+12.5.sgf gnugo-gnugo-396.B+4.5.sgf gnugo-gnugo-397.W+53.5.sgf gnugo-gnugo-398.B+2.5.sgf gnugo-gnugo-399.B+18.5.sgf";
string GLOBALOVERNIGHT3 = "fuego-fuego-22.B+4.5.sgf fuego-gnugo-167.B+0.5.sgf gnugo-fuego-242.W+1.5.sgf gnugo-fuego-296.W+1.5.sgf gnugo-gnugo-344.B+10.5.sgf"
" fuego-fuego-48.B+1.5.sgf fuego-gnugo-169.B+0.5.sgf gnugo-fuego-243.W+7.5.sgf gnugo-gnugo-300.W+1.5.sgf gnugo-gnugo-345.W+3.5.sgf"
" fuego-fuego-65.B+3.5.sgf fuego-gnugo-178.B+0.5.sgf gnugo-fuego-247.W+1.5.sgf gnugo-gnugo-307.B+22.5.sgf gnugo-gnugo-349.B+4.5.sgf"
" fuego-fuego-83.B+1.5.sgf fuego-gnugo-179.B+0.5.sgf gnugo-fuego-248.W+1.5.sgf gnugo-gnugo-310.W+1.5.sgf gnugo-gnugo-350.W+21.5.sgf"
" fuego-fuego-95.W+9.5.sgf fuego-gnugo-180.B+2.5.sgf gnugo-fuego-250.W+1.5.sgf gnugo-gnugo-311.W+3.5.sgf gnugo-gnugo-352.B+28.5.sgf"
" fuego-fuego-97.W+2.5.sgf fuego-gnugo-183.W+3.5.sgf gnugo-fuego-251.W+1.5.sgf gnugo-gnugo-312.W+13.5.sgf gnugo-gnugo-354.B+36.5.sgf"
" fuego-gnugo-100.B+2.5.sgf fuego-gnugo-185.B+0.5.sgf gnugo-fuego-256.W+1.5.sgf gnugo-gnugo-315.W+13.5.sgf gnugo-gnugo-359.B+24.5.sgf"
" fuego-gnugo-101.B+0.5.sgf fuego-gnugo-193.B+0.5.sgf gnugo-fuego-257.W+1.5.sgf gnugo-gnugo-319.B+0.5.sgf gnugo-gnugo-360.B+2.5.sgf"
" fuego-gnugo-104.B+0.5.sgf gnugo-fuego-203.W+1.5.sgf gnugo-fuego-258.W+1.5.sgf gnugo-gnugo-320.B+14.5.sgf gnugo-gnugo-364.W+5.5.sgf"
" fuego-gnugo-108.B+2.5.sgf gnugo-fuego-207.W+1.5.sgf gnugo-fuego-259.B+2.5.sgf gnugo-gnugo-328.B+0.5.sgf gnugo-gnugo-367.W+13.5.sgf"
" fuego-gnugo-111.B+2.5.sgf gnugo-fuego-208.W+1.5.sgf gnugo-fuego-262.W+1.5.sgf gnugo-gnugo-329.W+5.5.sgf gnugo-gnugo-368.W+1.5.sgf"
" fuego-gnugo-112.B+0.5.sgf gnugo-fuego-211.B+30.5.sgf gnugo-fuego-263.W+1.5.sgf gnugo-gnugo-332.W+11.5.sgf gnugo-gnugo-371.B+0.5.sgf"
" fuego-gnugo-116.B+2.5.sgf gnugo-fuego-214.W+1.5.sgf gnugo-fuego-264.W+5.5.sgf gnugo-gnugo-333.B+6.5.sgf gnugo-gnugo-372.W+3.5.sgf"
" fuego-gnugo-120.B+8.5.sgf gnugo-fuego-215.W+3.5.sgf gnugo-fuego-265.W+5.5.sgf gnugo-gnugo-334.B+8.5.sgf gnugo-gnugo-376.W+3.5.sgf"
" fuego-gnugo-123.B+0.5.sgf gnugo-fuego-220.W+1.5.sgf gnugo-fuego-268.W+1.5.sgf gnugo-gnugo-335.B+36.5.sgf gnugo-gnugo-379.W+7.5.sgf"
" fuego-gnugo-136.B+0.5.sgf gnugo-fuego-223.W+1.5.sgf gnugo-fuego-269.W+3.5.sgf gnugo-gnugo-336.W+11.5.sgf gnugo-gnugo-384.B+58.5.sgf"
" fuego-gnugo-140.B+0.5.sgf gnugo-fuego-224.W+1.5.sgf gnugo-fuego-272.W+1.5.sgf gnugo-gnugo-337.B+0.5.sgf gnugo-gnugo-385.B+20.5.sgf"
" fuego-gnugo-146.B+0.5.sgf gnugo-fuego-226.W+1.5.sgf gnugo-fuego-277.W+1.5.sgf gnugo-gnugo-338.B+10.5.sgf gnugo-gnugo-388.W+35.5.sgf"
" fuego-gnugo-152.B+0.5.sgf gnugo-fuego-228.W+5.5.sgf gnugo-fuego-281.W+1.5.sgf gnugo-gnugo-339.W+9.5.sgf gnugo-gnugo-390.W+13.5.sgf"
" fuego-gnugo-155.B+0.5.sgf gnugo-fuego-230.W+1.5.sgf gnugo-fuego-283.W+1.5.sgf gnugo-gnugo-340.W+13.5.sgf gnugo-gnugo-394.B+30.5.sgf"
" fuego-gnugo-158.B+0.5.sgf gnugo-fuego-233.W+9.5.sgf gnugo-fuego-289.W+1.5.sgf gnugo-gnugo-341.B+12.5.sgf gnugo-gnugo-395.W+5.5.sgf"
" fuego-gnugo-161.B+0.5.sgf gnugo-fuego-235.W+1.5.sgf gnugo-fuego-291.W+1.5.sgf gnugo-gnugo-342.B+40.5.sgf"
" fuego-gnugo-163.B+0.5.sgf gnugo-fuego-239.B+2.5.sgf gnugo-fuego-293.W+9.5.sgf gnugo-gnugo-343.W+13.5.sgf";
string GLOBALOVERNIGHT2 = "fuego-fuego-24.W+20.5.sgf fuego-gnugo-145.B+0.5.sgf  gnugo-fuego-210.W+1.5.sgf gnugo-fuego-263.W+3.5.sgf gnugo-gnugo-314.W+11.5.sgf gnugo-gnugo-357.B+20.5.sgf"
"fuego-fuego-27.B+2.5.sgf fuego-gnugo-148.B+0.5.sgf gnugo-fuego-211.W+1.5.sgf gnugo-fuego-264.W+1.5.sgf gnugo-gnugo-317.B+12.5.sgf gnugo-gnugo-360.B+14.5.sgf"
"fuego-fuego-39.B+33.5.sgf fuego-gnugo-149.B+0.5.sgf gnugo-fuego-212.W+1.5.sgf gnugo-fuego-265.W+1.5.sgf gnugo-gnugo-318.B+4.5.sgf gnugo-gnugo-361.W+7.5.sgf"
"fuego-fuego-40.W+2.5.sgf fuego-gnugo-151.B+4.5.sgf gnugo-fuego-216.W+1.5.sgf gnugo-fuego-268.W+3.5.sgf gnugo-gnugo-319.B+18.5.sgf gnugo-gnugo-362.B+30.5.sgf"
"fuego-fuego-64.W+2.5.sgf fuego-gnugo-153.B+0.5.sgf gnugo-fuego-217.W+3.5.sgf gnugo-fuego-269.W+1.5.sgf gnugo-gnugo-320.W+21.5.sgf gnugo-gnugo-363.B+18.5.sgf"
"fuego-fuego-75.W+5.5.sgf fuego-gnugo-154.B+0.5.sgf gnugo-fuego-218.W+1.5.sgf gnugo-fuego-270.B+2.5.sgf gnugo-gnugo-321.W+3.5.sgf gnugo-gnugo-364.B+14.5.sgf"
"fuego-fuego-9.B+3.5.sgf fuego-gnugo-157.B+0.5.sgf gnugo-fuego-220.W+1.5.sgf gnugo-fuego-271.W+1.5.sgf gnugo-gnugo-322.B+6.5.sgf gnugo-gnugo-365.B+78.5.sgf"
"fuego-fuego-93.B+12.5.sgf fuego-gnugo-159.B+0.5.sgf gnugo-fuego-223.W+1.5.sgf gnugo-fuego-272.W+1.5.sgf gnugo-gnugo-323.B+16.5.sgf gnugo-gnugo-366.B+8.5.sgf"
"fuego-gnugo-100.B+0.5.sgf fuego-gnugo-160.B+4.5.sgf gnugo-fuego-224.W+3.5.sgf gnugo-fuego-273.W+5.5.sgf gnugo-gnugo-324.W+31.5.sgf gnugo-gnugo-367.W+9.5.sgf"
"fuego-gnugo-101.B+2.5.sgf fuego-gnugo-164.B+0.5.sgf gnugo-fuego-226.W+3.5.sgf gnugo-fuego-274.W+5.5.sgf gnugo-gnugo-325.B+18.5.sgf gnugo-gnugo-368.B+16.5.sgf"
"fuego-gnugo-102.B+0.5.sgf fuego-gnugo-165.B+0.5.sgf gnugo-fuego-227.W+1.5.sgf gnugo-fuego-277.W+3.5.sgf gnugo-gnugo-327.W+27.5.sgf gnugo-gnugo-370.W+39.5.sgf"
"fuego-gnugo-103.B+2.5.sgf fuego-gnugo-166.B+2.5.sgf gnugo-fuego-228.W+1.5.sgf gnugo-fuego-279.B+2.5.sgf gnugo-gnugo-328.B+2.5.sgf gnugo-gnugo-371.B+32.5.sgf"
"fuego-gnugo-104.B+0.5.sgf fuego-gnugo-167.B+2.5.sgf gnugo-fuego-230.B+2.5.sgf gnugo-fuego-284.W+3.5.sgf gnugo-gnugo-329.B+4.5.sgf gnugo-gnugo-373.B+46.5.sgf"
"fuego-gnugo-105.B+0.5.sgf fuego-gnugo-171.B+2.5.sgf gnugo-fuego-231.W+1.5.sgf gnugo-fuego-285.W+1.5.sgf gnugo-gnugo-331.W+11.5.sgf gnugo-gnugo-374.W+7.5.sgf"
"fuego-gnugo-106.B+2.5.sgf fuego-gnugo-172.B+2.5.sgf gnugo-fuego-232.W+3.5.sgf gnugo-fuego-286.W+1.5.sgf gnugo-gnugo-332.W+9.5.sgf gnugo-gnugo-375.B+40.5.sgf"
"fuego-gnugo-110.B+0.5.sgf fuego-gnugo-174.B+0.5.sgf gnugo-fuego-233.W+3.5.sgf gnugo-fuego-288.W+3.5.sgf gnugo-gnugo-333.W+13.5.sgf gnugo-gnugo-377.W+25.5.sgf"
"fuego-gnugo-115.B+0.5.sgf fuego-gnugo-175.B+0.5.sgf gnugo-fuego-234.W+3.5.sgf gnugo-fuego-290.W+1.5.sgf gnugo-gnugo-334.W+9.5.sgf gnugo-gnugo-378.W+5.5.sgf"
"fuego-gnugo-116.B+0.5.sgf fuego-gnugo-176.B+0.5.sgf gnugo-fuego-237.W+1.5.sgf gnugo-fuego-291.W+7.5.sgf gnugo-gnugo-335.W+7.5.sgf gnugo-gnugo-381.W+3.5.sgf"
"fuego-gnugo-117.B+0.5.sgf fuego-gnugo-178.B+0.5.sgf gnugo-fuego-238.W+1.5.sgf gnugo-fuego-292.W+1.5.sgf gnugo-gnugo-336.B+14.5.sgf gnugo-gnugo-382.B+4.5.sgf"
"fuego-gnugo-118.B+2.5.sgf fuego-gnugo-181.B+2.5.sgf gnugo-fuego-239.W+1.5.sgf gnugo-fuego-294.W+1.5.sgf gnugo-gnugo-337.W+19.5.sgf gnugo-gnugo-383.W+17.5.sgf"
"fuego-gnugo-120.B+0.5.sgf fuego-gnugo-182.B+0.5.sgf gnugo-fuego-240.W+1.5.sgf gnugo-fuego-296.W+1.5.sgf gnugo-gnugo-339.B+4.5.sgf gnugo-gnugo-384.W+5.5.sgf"
"fuego-gnugo-121.B+0.5.sgf fuego-gnugo-183.B+0.5.sgf gnugo-fuego-241.B+6.5.sgf gnugo-fuego-297.W+1.5.sgf gnugo-gnugo-340.B+24.5.sgf gnugo-gnugo-385.B+6.5.sgf"
"fuego-gnugo-122.B+0.5.sgf fuego-gnugo-185.B+0.5.sgf gnugo-fuego-242.W+1.5.sgf gnugo-gnugo-300.B+20.5.sgf gnugo-gnugo-342.W+1.5.sgf gnugo-gnugo-386.B+6.5.sgf"
"fuego-gnugo-123.B+2.5.sgf fuego-gnugo-187.B+0.5.sgf gnugo-fuego-246.W+1.5.sgf gnugo-gnugo-301.B+8.5.sgf gnugo-gnugo-343.W+15.5.sgf gnugo-gnugo-388.B+10.5.sgf"
"fuego-gnugo-124.B+0.5.sgf fuego-gnugo-191.B+4.5.sgf gnugo-fuego-250.W+1.5.sgf gnugo-gnugo-302.W+79.5.sgf gnugo-gnugo-344.B+14.5.sgf gnugo-gnugo-389.W+9.5.sgf"
"fuego-gnugo-127.B+0.5.sgf fuego-gnugo-193.B+0.5.sgf gnugo-fuego-251.W+1.5.sgf gnugo-gnugo-304.W+13.5.sgf gnugo-gnugo-345.B+2.5.sgf gnugo-gnugo-390.B+10.5.sgf"
"fuego-gnugo-129.B+0.5.sgf fuego-gnugo-194.B+6.5.sgf gnugo-fuego-252.W+1.5.sgf gnugo-gnugo-305.W+39.5.sgf gnugo-gnugo-348.B+2.5.sgf gnugo-gnugo-392.B+34.5.sgf"
"fuego-gnugo-130.B+0.5.sgf fuego-gnugo-195.B+2.5.sgf gnugo-fuego-253.W+1.5.sgf gnugo-gnugo-306.B+2.5.sgf gnugo-gnugo-349.W+3.5.sgf gnugo-gnugo-393.B+2.5.sgf"
"fuego-gnugo-133.W+1.5.sgf fuego-gnugo-197.B+0.5.sgf gnugo-fuego-255.W+5.5.sgf gnugo-gnugo-307.B+14.5.sgf gnugo-gnugo-350.W+15.5.sgf gnugo-gnugo-394.W+45.5.sgf"
"fuego-gnugo-135.B+2.5.sgf fuego-gnugo-199.B+0.5.sgf gnugo-fuego-256.W+1.5.sgf gnugo-gnugo-308.W+27.5.sgf gnugo-gnugo-351.B+0.5.sgf gnugo-gnugo-395.W+21.5.sgf"
"fuego-gnugo-136.B+0.5.sgf gnugo-fuego-202.W+1.5.sgf gnugo-fuego-258.W+1.5.sgf gnugo-gnugo-310.B+14.5.sgf gnugo-gnugo-352.W+47.5.sgf gnugo-gnugo-396.B+30.5.sgf"
"fuego-gnugo-140.B+2.5.sgf gnugo-fuego-203.W+1.5.sgf gnugo-fuego-259.W+1.5.sgf gnugo-gnugo-311.W+29.5.sgf gnugo-gnugo-353.B+6.5.sgf gnugo-gnugo-397.W+7.5.sgf"
"fuego-gnugo-142.B+4.5.sgf gnugo-fuego-204.W+1.5.sgf gnugo-fuego-260.W+1.5.sgf gnugo-gnugo-312.B+10.5.sgf gnugo-gnugo-354.B+4.5.sgf gnugo-gnugo-398.W+19.5.sgf"
"fuego-gnugo-143.B+0.5.sgf gnugo-fuego-208.W+1.5.sgf gnugo-fuego-262.W+1.5.sgf gnugo-gnugo-313.B+0.5.sgf gnugo-gnugo-356.W+53.5.sgf";

struct GameInfo {
    int gnuGoBlackWins = 0;
    int gnuGoWhiteWins = 0;
    int fuegoBlackWins = 0;
    int fuegoWhiteWins = 0;
    int totalGames = 0;
};

enum MATCHES {
    GnuGoVsFuego = 0,
    FuegoVsGnuGo,
    FuegoVsFuego,
    GnuGoVsGnuGo
};


vector<string> const createVector(string &input) {
    std::vector<std::string> words;
    std::istringstream iss(input);
    std::string word;
    while (iss >> word) {
        std::cout << word << std::endl;
        words.push_back(word);
    }
    return words;
}

int main()
{
    // std::cout << GLOBAL << std::endl;
    // createVector(GLOBAL);
    string s = "gnugo-fuego-259.B+2.5.sgf";
    string GLOBAL = GLOBALOVERNIGHT3 + " " + GLOBALOVERNIGHT2 + " " + overnight4;
    vector<string> inputs = createVector(GLOBAL);
    vector<GameInfo> res(4, GameInfo{});
    
    std::regex pattern("[B|W][+][0-9]*[.][5]");
    
    for (const auto &str: inputs) {
        string firstArg = "";
        string secondArg = "";
        
        istringstream ss(str);
        std::getline(ss, firstArg, '-');
        std::getline(ss, secondArg, '-');
        
        std::smatch matches;
        if (!std::regex_search(str, matches, pattern)) {
            throw std::runtime_error("Something went wrong during execution!");
        }
        std::cout << matches.str() << std::endl;
        
        string regex_res = matches.str();
        
        if (firstArg == "fuego" && secondArg == "gnugo") {
            
            res[MATCHES::FuegoVsGnuGo].totalGames += 1;
            if (regex_res[0] == 'W') {
                res[MATCHES::FuegoVsGnuGo].gnuGoWhiteWins += 1;
            } else if (regex_res[0] == 'B'){
                res[MATCHES::FuegoVsGnuGo].fuegoBlackWins += 1;
            } else {
              throw std::runtime_error("Something went wrong during execution!");  
            }
            
        } else if (firstArg == "gnugo" && secondArg == "fuego") {
            res[MATCHES::GnuGoVsFuego].totalGames += 1;
            
            if (regex_res[0] == 'W') {
                res[MATCHES::GnuGoVsFuego].fuegoWhiteWins += 1;
            } else if (regex_res[0] == 'B'){
                res[MATCHES::GnuGoVsFuego].gnuGoBlackWins += 1;
            } else {
              throw std::runtime_error("Something went wrong during execution!");  
            }
            
        } else if (firstArg == "fuego" && secondArg == "fuego") {
            res[MATCHES::FuegoVsFuego].totalGames += 1;
            
            if (regex_res[0] == 'W') {
                res[MATCHES::FuegoVsFuego].fuegoWhiteWins += 1;
            } else if (regex_res[0] == 'B'){
                res[MATCHES::FuegoVsFuego].fuegoBlackWins += 1;
            } else {
              throw std::runtime_error("Something went wrong during execution!");  
            }
            
        } else if (firstArg == "gnugo" && secondArg == "gnugo") {
            res[MATCHES::GnuGoVsGnuGo].totalGames += 1;
            
            if (regex_res[0] == 'W') {
                res[MATCHES::GnuGoVsGnuGo].gnuGoWhiteWins += 1;
            } else if (regex_res[0] == 'B'){
                res[MATCHES::GnuGoVsGnuGo].gnuGoBlackWins += 1;
            } else {
              throw std::runtime_error("Something went wrong during execution!");  
            }
        }
        
    }
    
    for (int i = 0; i < res.size(); ++i) {
        if (i == MATCHES::GnuGoVsFuego) {
            std::cout << "GnuGoVsFuego: ";
            std::cout << "Black Win: " << res[i].gnuGoBlackWins;
            std::cout << " White Win: " << res[i].fuegoWhiteWins;
        } else if (i == MATCHES::FuegoVsGnuGo) {
            std::cout << "FuegoVsGnuGo: ";
            std::cout << "Black Win: " << res[i].fuegoBlackWins;
            std::cout << "White Win: " << res[i].gnuGoWhiteWins;
        } else if (i == MATCHES::FuegoVsFuego) {
            std::cout << "FuegoVsFuego: ";
            std::cout << "Black Win: " << res[i].fuegoBlackWins;
            std::cout << "White Win: " << res[i].fuegoWhiteWins;
        } else if (i == MATCHES::GnuGoVsGnuGo) {
            std::cout << "GnuGoVsGnuGo: ";
            std::cout << "Black Win: " << res[i].gnuGoBlackWins;
            std::cout << "White Win: " << res[i].gnuGoWhiteWins;
        }
        std::cout << " Total Games: " << res[i].totalGames << std::endl;
    }
    
    
    return 0;
}
