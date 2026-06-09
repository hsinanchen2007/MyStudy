### 解题思路
遍历houses数组的每一元素，求每一元素到其最近的左、右取暖器的距离的最小值，最后取这些最小值中的最大一个即是答案。


那么怎么求每一元素到其最近的左 右取暖器的距离？

二分：通过与heaters数组比较，从mid开始比，比heaters[mid]大往右子树走，比heaters[mid]小往左子树走，每趟比较都得记录临时最小temp值，..........直到left大于right，当然如果==，则本元素的最小距离为0，退出本次循环直接进行下一元素。

### 代码

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());                //先对两个数组进行排序
        int max = INT_MIN;
        for(int i=0;i<houses.size();i++)
        {
            int left = 0 ,right = heaters.size()-1,mid;
            int temp = INT_MAX;
            while(left<=right)
            {            
                mid = left+(right-left)/2;              //这样写防止left+right 超出限制
                if(heaters[mid] == houses[i])
                {
                    temp = 0;
                    break;                              //相等直接不用比，距离为0
                }
                else if(heaters[mid]>houses[i])        
                {
                    temp = min(temp,heaters[mid]-houses[i]);
                    right = mid-1;                      //往heaters左子树走
                }
                else
                {
                    temp = min(temp,houses[i]-heaters[mid]);
                    left = mid +1;                      //往heaters右子树走
                }
            }
            max = max<temp?temp:max;            //每趟比出的min值与已有的max再进行对比
        }
        return max;
    }
};
```