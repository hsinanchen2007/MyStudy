### 解题思路
Nums为有序数组旋转产生的数组，只需找到旋转前的第一个点位，即为排序数组中的最小值

### 代码

```cpp
class Solution {
public:
	int findMin(vector<int>& nums) {
		int length=nums.size();
        if(length==1)                       //若数组中只有一个元素，nums[0]为最小
            return nums[0];         
        int dot=length;                     //定义dot为旋转前的第一个点
        for(int i=1;i<length;i++){
            if(nums[i]<nums[i-1]){          //dot的条件为dot处的元素值小于前一个
                dot=i;
                break;
            }
        }
        if(dot<length)
            return nums[dot];               //如果dot<length，说明找到了dot,此点为最小
        else
            return nums[0];                 //否则nums[0]为最小
	}
};

```