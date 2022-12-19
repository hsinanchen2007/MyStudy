```
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int balloon[5] = {0};
        for(int i = 0; i < text.size(); ++i) {
            switch(text[i]){
                case 'b': balloon[0]++;break; 
                case 'a': balloon[1]++;break; 
                case 'l': balloon[2]++;break; 
                case 'o': balloon[3]++;break; 
                case 'n': balloon[4]++;break; 
            }
        }
        int count = 0;
        while(balloon[0] >= 1 && balloon[1] >= 1 && balloon[2] >= 2 && balloon[3] >= 2 && balloon[4] >= 1) {
            balloon[0]--;
            balloon[1]--;
            balloon[2] = balloon[2] - 2;
            balloon[3] = balloon[3] - 2;
            balloon[4]--;
            count++;
        }
        return count;
    }
};
```
![image.png](https://pic.leetcode-cn.com/dbc394a3b0749b966dc72b191418bd8301369d0f22e9a75d648d565bb9786f08-image.png)
