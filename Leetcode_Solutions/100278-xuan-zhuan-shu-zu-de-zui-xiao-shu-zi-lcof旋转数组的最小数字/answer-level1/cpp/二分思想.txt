存在三种情况：
1.mid>right
即[3,4,5,1,2]  那么带查找区间在右侧，即right=mid+1;
2.mid==right
即[3,4,1,1,1]  那么需要缩小待查找区间，即right--;
3.mid<right
即[1,2,3,4,5]   那么待查找区间在左侧，即left=mid;

```C++ []
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size=numbers.size();
        if(size==0)
        return 0;

        int left=0;
        int right=size-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(numbers[mid]>numbers[right])
            {
                left=mid+1;
            }
            else if(numbers[mid]==numbers[right])
            {
                right--;
            }
            else 
            {
                right=mid;
            }
        }
        return numbers[left];

    }
};
```


