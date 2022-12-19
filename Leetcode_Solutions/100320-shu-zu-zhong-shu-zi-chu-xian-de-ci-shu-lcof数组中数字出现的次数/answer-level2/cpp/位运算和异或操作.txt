
### 代码

```cpp
class Solution {
public:
    /*
    1、首先我们需要知道两个相同的数异或的结果为0，因此如果该数组是只有一个数出现一次，只需要把所有数异或一遍     就可以得到结果
    2、但是这里存在两个只有一个的数，因此我们需要将该数组分为两组，每一组都只包含一个存在一个的数
    3、如何分呢，首先我们需要知道一个数的相反数等于该数取反之后加1，因此我们可以找到一个数最右边的1的位置为
    (num&-num),如（010&110）=010
    4、然后我们将所有数异或后得到一个数，该数为两个出现一次的数的异或，不可能为0，求最右边1出现的位置
    5、最后我们遍历数组，将每个数都和4中得到的数的最右边1的位置进行&，为1的是一组，否则为另一组，得出结果
    */
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res(2);
        int n=nums.size();
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=temp^nums[i];
        }
        int pos=temp&(-temp);
        int f=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&pos)
                f=f^nums[i];
            else
            {
                b=b^nums[i];
            }
        }
        res[0]=f;
        res[1]=b;
        return res;
    }
};
```