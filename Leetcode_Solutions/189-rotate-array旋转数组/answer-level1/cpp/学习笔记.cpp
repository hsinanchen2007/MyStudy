第一次想到使用的是官方的方法2，时间复杂度为O(n)，空间复杂度为O(n)

后来看了官方答案，整理如下：
/*
循环替换法：
详细方法为：直接把一个数字放到它最后的位置，替换前把之前的数字保存到一个临时变量temp中，然后将temp放到它正确的位置，并继续这个过程n次，n为数组的长度。如下：

```
nums: [1, 2, 3, 4, 5, 6]
k: 2
```
![f0493a97cdb7bc46b37306ca14e555451496f9f9c21effcad8517a81a26f30d6-image.png](https://pic.leetcode-cn.com/313cc3fed68ce5847fa08599ad76bbd9e843a0029e18046fc3bd2389a7ec6a75-f0493a97cdb7bc46b37306ca14e555451496f9f9c21effcad8517a81a26f30d6-image.png)



该算法的时间复杂度为: O(n)
空间复杂度为:O(1)

示例1和2为基本情况，一次循环就可以替换完成，示例3为特殊情况，需要多个循环替换!

可以发现规律：
nums.size() % k != 0，为基本情况，否则为特殊情况

设计时需要考虑特殊情况

示例1：
1,2,3,4,5,6,7  k=2

格式：
新序列
temp位置

初始:
1,2,3,4,5,6,7

一：
1,2,1,4,5,6,7
    3
二：
1,2,1,4,3,6,7
        5
三：
1,2,1,4,3,6,5
            7
四：
1,7,1,4,3,6,5
  2          
五：
1,7,1,2,3,6,5
      4          
六：
1,7,1,2,3,4,5
          6      
七：
6,7,1,2,3,4,5
1                


示例2：                                                                                                                                               
1,2,3,4   k = 3

初始：
1,2,3,4

一：
1,2,3,1
      4
二：
1,2,4,1
    3  
三：
1,3,4,1
  2    
四：
2,3,4,1
1     


示例3：
1,2,3,4   k = 2

初始：
1,2,3,4

一：
1,2,1,4
    3
二：
3,2,1,4
1 
first loop end

三：
3,2,1,2
      4
四：
3,4,1,2
  2    
second loop end
次数到达4次，结束

计算如下：
假如包含n个元素，总共移动的次数为n次，那么，
时间复杂度为：O(n)

使用了常数个变量，所以空间复杂度为:O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

/*
1. 需要记录执行次数, count;
2. 需要记录跳转替换时，
   单个循环跳转的起始位置：pos_start
   每个循环跳转中，单次跳转的当前位置：pos_per_start，以及值：val_per_start
   跳转至的位置：pos_per_next，以及pos_per_next之前的值：val_per_next
 */

void rotate(vector<int>& nums, int k)
{
        for (int count = 0, pos_start=0; count < nums.size(); pos_start++) {
                int pos_per_start = pos_start;
                int val_per_start = nums[pos_start];
                do {
                        int pos_per_next = (pos_per_start+k) % nums.size();
                        int val_per_next = nums[pos_per_next];

                        /* 覆盖 */
                        nums[pos_per_next] = val_per_start;
                        /* 把当前的next之前保存的值，作为下一次start的值 */
                        val_per_start = val_per_next; 
                        pos_per_start = pos_per_next;
                        count ++;
                } while (pos_start != pos_per_start);
        }
}

int main(void)
{
        vector<int> nums {1,2,3,4,5,6,7};
        int k = 3;

        rotate(nums, k);

        for (auto& k:nums)
                cout << k << " ";
        cout<<endl;

        return 0;
}

运行结果：
5 6 7 1 2 3 4 


