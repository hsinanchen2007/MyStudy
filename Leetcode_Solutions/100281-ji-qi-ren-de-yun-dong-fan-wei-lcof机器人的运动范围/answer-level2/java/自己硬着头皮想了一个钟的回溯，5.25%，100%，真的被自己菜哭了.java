### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int[] dx = new int[]{0, 0, 1, -1};
    private int[] dy = new int[]{1, -1, 0, 0};
    private int tmp = 0;
    private int ans = 0;
    List<String> list = new ArrayList<>();
    public int movingCount(int m, int n, int k) {
        list.add("(0,0)");
        move(0, 0, m, n, k);
        return ans;
    }

    public void move(int x, int y, int m, int n, int k){
        if(x < 0 || y < 0 || x >= m || y >= n){
            return;
        }
        tmp = x;
        int sum1 = 0;
        int sum2 = 0;
        while(tmp != 0){
            sum1 += tmp%10;
            tmp /= 10;
        }
        tmp = y;
        while(tmp != 0){
            sum2 += tmp%10;
            tmp /= 10;
        }

        if(sum1 + sum2 <= k){
            ans++;
        }

        for(int i = 0; i < 4; i++){
            if(sum1 + sum2 <= k){
                x += dx[i];
                y += dy[i];
                String s = "(" + x + "," + y + ")";
                if(list.indexOf(s) != -1){
                    
                    continue;
                }
                list.add(s);
                move(x, y, m, n, k);
            }
            else{
                return;
            }
        }
    }
}
```