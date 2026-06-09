```
class Solution {
public:
    int flipLights(int n, int m) {
        switch(n)
        {
            case 1:
            {
                return m>0?2:1;
            }
            case 2:
            {
                switch(m)
                {
                    case 0:return 1;
                    case 1:return 3;
                    default:return 4;
                }
            }
            default:
            {
                switch(m)
                {
                    case 0:return 1;
                    case 1:return 4;
                    case 2:return 7;
                    default:return 8;
                }
            }
        }
    }
};
```
