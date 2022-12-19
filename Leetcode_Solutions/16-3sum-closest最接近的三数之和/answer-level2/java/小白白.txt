步骤1.先排序，呈递增的序列
步骤2.设置Current,Left,Right三个答案的下标索引变量,默认排列顺序是Current < Left < Right
步骤3.设置aboveTarget（默认值设置成一个很大的值），belowTarget（默认值设置成一个很小的值）。两个变量的含义：大于target且最接近target的值和小于target且最接近target的值，比如数列-50，-2,0,500,1000，在target为0时，大于他且最接近他的值为500（aboveTarget）,小于他且最接近他的值是-2（belowTarget）
步骤4.确定一共有两层嵌套循环，外层循环和内层循环
步骤5.外层循环先确定答案的最左边的元素，及Current索引值，区间范围是[0-nums.length-3].注：因为要留最少两个元素给Left（nums.length-2）和Right(nums.length-1)
步骤6.当Current 确定的时候，设置Left和Right初始值，Left都从Current +1 开始，Right从nums.length-1开始
步骤7.内层循环开始,判断是否Left < Right,true进入内层循环内部，false跳出内层循环并且跳到步骤13
步骤8.进入内层循环后
步骤9.计算nums[Current]+nums[Left]+nums[Right]得到一个临时和sum
步骤10.当sum == target,返回target跳出函数
步骤11.当sum > target时，判断此时sum跟aboveTarget相比，哪一个更小，也就是在我们都大于target的情况下,越小的值就是最接近target的值，更新aboveTarget(当sum小于aboveTarget,将sum赋值给aboveTarget)。为了使接下来内层循环的sum变小来接近target，Right减一，内层一次循环结束，跳到步骤7
步骤12.当sum < target时，判断此时sum跟belowTarget相比，哪一个更大，也就是在我们都小于target的情况下,越大的值就是最接近target的值，更新belowTarget(当sum大于belowTarget,将sum赋值给belowTarget)。为了使接下来内层循环的sum变大来接近target，Left加一，内层一次循环结束，跳到步骤7
步骤13.更新Current，使其加一，判断是否在区间内，在就回到步骤6，不在就跳到步骤15
步骤15.当外层循环全部都结束后，查看aboveTarget跟belowTarget哪一个跟接近target,返回最接近的那一个，函数结束


