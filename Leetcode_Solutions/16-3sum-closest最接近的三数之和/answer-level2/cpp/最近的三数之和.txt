思路：采用一次循环加双指针的方法去完成，一次循环指的是第一个数用一遍循环确定，双指针分别指向已经排好序的头和尾，头和尾分别代表第二个数和第三个数，根据当前三个数的和与target的大小关系去移动头和尾，以及不断的改变第一个数。
步骤如下：

1.异常判断，这里是数组大小是否为空或小于3
2.数组排序，在原数组上进行
3.for循环确定第一个数的值，头尾指针重新设定
4.while循环确定循环条件，头指针小于尾指针
5.while循环体中计算三数之和，比较最优解和当前解与target的差距，若当前解更优则更新
6.比较当前解与target的大小关系，移动头尾指针
7.返回最优解

实现：

```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        
        int target_dis;
        if(nums.size() >= 3)
        target_dis = nums[0] + nums[1] + nums[2];
    
        sort(nums.begin(),nums.end());   
        
        for(int i = 0 ; i < nums.size() - 2; i ++)
        {
            int left = i + 1, right = nums.size() - 1; 
            while((left < right ) && left < nums.size() && right > 0)
            {
                int sum = nums[i] + nums[left] + nums[right];
                // cout << "     " <<nums[i] << "     " << nums[left] << "     " << nums[right] <<endl;
                int distance = target_dis - target;
                distance = distance > 0 ? distance:(0-distance);
                int sum_distance = sum - target;
                sum_distance = sum_distance > 0 ? sum_distance:(0-sum_distance);  
                if(distance > sum_distance)
                {
                    target_dis = sum;
                    
                    if(target_dis == target)
                        break;
                }
                if(sum > target)
                    right --;
                else
                    left ++;
            }
            if(target_dis == target)
                break;
        }
        return target_dis;  
    }
};
```