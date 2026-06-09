### 解题思路


采用有限状态自动机解决问题，其实核心思想就是使用一个枚举变量指示当前方向，使用结构体指示当前情况下每个方向的极限，然后自动机状态转化判断当前状态同时写入数组即可。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // 使用一个指示表示当前方向，并使用四个数值标记当前方向所能达到的最远位置



        int m=matrix.size();
        vector<int> test;

        if (m==0)
            return test;

        int n=matrix[0].size();
        
        if(n==0)
            return test;

        enum direction {
            UP,
            DOWN,
            LEFT,
            RIGHT,
        };

        struct limit{
            int left;
            int right;
            int up;
            int down;
        };

        struct limit Limit = {
                .left=0,
                .right=n-1,
                .up=1,
                .down=m-1,
        };

        direction D = RIGHT;

        int i=0;
        int j=0;



        while(test.size()!=n*m){
    //        cout << "j--" << j << "--i--" << i << "--num--" << matrix[j][i] << endl;
    //        cout << "D--" << D  << "---k---" << k << endl;

            switch (D) {
                case RIGHT:
                    if (i > Limit.right){
                        D = DOWN;
                        Limit.right--;
                        i--;
                        test.pop_back();
                    }
                    else{
                        test.push_back(matrix[j][i]);
                        i++;
                    }
                    break;

                case DOWN:
                    if (j > Limit.down){
                        D = LEFT;
                        Limit.down--;
                        j--;
                        test.pop_back();
                    }
                    else {
                        test.push_back(matrix[j][i]);
                        j++;
                    }
                    break;
                case LEFT:
                    if(i < Limit.left){
                        D = UP;
                        Limit.left++;
                        i++;
                        test.pop_back();
                    }
                    else{
                        test.push_back(matrix[j][i]);
                        i--;
                    }
                    break;
                case UP:
                    if(j < Limit.up){
                        D=RIGHT;
                        Limit.up++;
                        j++;
                        test.pop_back();
                    }
                    else{
                        test.push_back(matrix[j][i]);
                        j--;
                    }
                default:
                    break;
            }
        }

        return test;

        
        
        
    }
};
```