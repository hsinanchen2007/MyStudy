### 解题思路
![E~~1GJA1DFVT3ZH`~G_0I9Q.png](https://pic.leetcode-cn.com/52f1a453eae4d074b31d6b82a2a5ce92288524753591374b81c2852dad54ed35-E~~1GJA1DFVT3ZH%60~G_0I9Q.png)
思路：
要求时间O(n)空间O(1)就只能顺序遍历，且在原数组上做文章-->否定常规排序
求没出现过的最小整数-->维护一个变量min,代表遍历到当前时刻没出现过的最小整数

初始化min==1
简单分析可以发现：
1.所有非正整数肯定不是最终结果
2.所有大于n的数肯定不是最终结果
称以上两种数为非法数，其余为合法数

问题1：当1出现过后怎么更新min
问题2：下一次查找从哪儿开始？

解决问题1：
如果找到min时，min+1也已经出现过，min肯定更新为大于min+1的值-->要求我们把出现过的所有合法值标记上-->标记方法：桶排思想，某个合法值出现过就在对应下标添上该值。如2出现过，list[1]=2,这样更新min的时候先令list[min-1]=min,之后从min-1顺序遍历找到第一个list[m-1]!=m的值，令min=m。

解决问题2：
如果再从头遍历找是否出现2、3....时间上肯定不是线性的-->下一次查找要从当前的下标i开始往后遍历-->要维护所有小于i的下标已经检查过-->保证所有小于i的下标，要么已经添上对应的值，要么为0，表示对应的值还没找到-->保证当前i操作完后的值满足检查过后的要求即可

具体实现：
对当前i的操作：
if(list[i] == min)
找到min,更新list[min-1] = min,更新min,并且令list[i] = 0,说明i+1还未出现过
elif (list[i]== i+1) 
位置正确，continue
elif(list[i]不合法) 令list[i] = 0，说明i+1还未出现过
elif(list[i] < i+1) 
前面某个合法值出现了，更新list[list[i]-1] = list[i],并且令list[i] = 0，说明i+1还未出现过
else
后面某个合法值出现了,交换两值,当交换过来的不是i+1且为合法值时,持续交换,直到找到i+1或者交换到非法值时停止，后续处理如上。

至此算法结束，但是还可以做一下优化：

上述else部分里相当于嵌套了一个小循环，好像会拖慢运行时间.

解决：
如果处理完i之后i后面的值都已经是位置恰当的合法值,不用继续向后遍历,直接跳出即可,即只要我们检查够n个合法值即可,维护一个valid变量表示合法值的检查次数,when valid == n,break;

注意：
出现相同值的时候要特判一下，具体看代码

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min = 1;
        int valid = 0;
        int len = nums.size();
        for(int i = 0 ;i < len; i++){
            if(valid == len)break;
            if(nums[i]==min){
                //找到min
                nums[min-1] = min;
                int j = min;
                //寻找下一个min
                while(j<len&&nums[j]==j+1)j++;
                min = j+1;
                if(j == len)break;
                nums[i] = 0;
                valid++;
            }
            //检查过的合法值
            else if(nums[i] == i+1)continue;
            else{
                //非法值
                if(nums[i]>len||nums[i]<=0)nums[i]=0;
                else if(nums[i]<i+1){
                    //前面某个合法值出现了
                    nums[nums[i]-1] = nums[i];
                }
                else{
                    if(nums[nums[i]-1] == nums[i]){
                        //出现相同值的情况
                        nums[i]=0;
                        valid--;
                    }
                    else{
                        //持续交换
                        int temp = nums[nums[i]-1];
                        nums[nums[i]-1] = nums[i];
                        nums[i] = temp;
                        i--;
                    }
                }
                valid++;
            }
        }
        return min;
    }
};
```