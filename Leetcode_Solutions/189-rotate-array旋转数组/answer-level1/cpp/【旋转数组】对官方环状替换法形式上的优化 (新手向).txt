	官方的环状替换法其实有一些变量是冗余的，比如current和next变量的功		

	能是重复的，所以对这个办法进行一些形式上的优化，并对整个代码所需要		

	的变量等做一些整理，帮助新手更容易理解代码。解题思路不在此做整理，		

	官方已经讲的很好了。
	
1.应该有变量1:start，标志小循环完全完成后，下一个完整的小循环开始的元素的位置，整个小循环结束后+1
2.应该有变量2和3:next_key和next_value,暂时记录下个位置的值和位置
3.应该有变量4:prev_value，记录被旋转的元素的value
4.应该有一个计数器count < nums.size(),作为大循环的结束条件
5.当start == next_key时，说明完成了一次小环，一个完整的小循环结束
6.只有n % k == 0时才会有多次小循环。
7.使用do while是因为当start == next_key时仍要先完成元素替换再终止循环。

一共需要4个变量和一个计数器即可。

代码如下:
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int len = nums.size();
        k = k % len;
        int count = 0;
        for (int start = 0; count < len; start++) {
        	int next_key = start;
            int prev_value = nums[start];
            do {
            	next_key = (k + next_key) % len;
				int next_value = nums[next_key];
            	nums[next_key] = prev_value;
                prev_value = next_value;
                count++;
            } while (next_key != start);
        }
        
    }
};
```
