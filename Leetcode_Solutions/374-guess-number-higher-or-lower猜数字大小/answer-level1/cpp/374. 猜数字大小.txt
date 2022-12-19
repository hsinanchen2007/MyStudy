```
class Solution {
public:
    int guessNumber(int n) {
        int low=1;
        int high=n;
        while(low<high)
        {
            int mid=low+((high-low)>>1);
            int tmp=guess(mid);
            switch(tmp)
            {
                case 0:
                {
                    return mid;
                }
                case 1:
                {
                    low=mid+1;
                    break;
                }
                case -1:
                {
                    high=mid-1;
                    break;
                }
            }
        }
        return high;
    }
};
```
