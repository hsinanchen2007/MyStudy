### 解题思路
练习使用堆排序对数组进行排序，返回中位数即是多数元素。

### 代码

```cpp
class Solution {
public:
    void Sift(vector<int> &R,int low,int high)
    {
        int i=low,j=i*2+1;          //下标从0开始，j指向i的左孩子结点
        int temp=R[i];              //保存i的值，用以调整
        while(j<high)
        {
            if(j<high&&R[j]<R[j+1]) //右孩子大，j指向右孩子
                ++j;
            if(temp<R[j])           //孩子结点大,将子结点上移,更新i,j的值方便继续调整
            {
                R[i]=R[j];
                i=j;
                j=2*i;
            }
            else
                break;
        }
        R[i]=temp;              //调整完毕
    }
    void heapsort(vector<int> &R)
    {
        int n=int(R.size());
        int i;
        int temp;
        for(i=n/2-1;i>=0;i--)   //建立初始堆
        {
            Sift(R,i,n-1);
        }
        //根结点关键字插入有序队列中，得到有序数组
        for(i=n-1;i>=1;--i)
        {
            temp=R[0];
            R[0]=R[i];
            R[i]=temp;
            Sift(R,0,i-1);
        }
    }
    int majorityElement(vector<int>& nums) {
        heapsort(nums);
        return (nums[nums.size()/2]);
    }
};//sort
```