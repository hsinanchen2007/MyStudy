### 解题思路
![chrome_2019-12-07_18-48-28.png](https://pic.leetcode-cn.com/18fafbe941de29059927b90a052931d7c621481c1378fd33b25c996d79004acc-chrome_2019-12-07_18-48-28.png)
![微信图片_20191207184950.jpg](https://pic.leetcode-cn.com/c624b77f3774f40382ff024ce8cd2af9f1b075b01e76b5673918bb2de0fa687e-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191207184950.jpg)
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length == 0) return new ArrayList<Integer>();
        int left = 0;
        int right = matrix[0].length - 1;
        int up = 0;
        int down = matrix.length - 1;
        int i = 0;
        int j = 0;
        List<Integer> list = new ArrayList<>();
        while(true){
            //右行到rigth边界，则up + 1
            if(i>= up && i<= down && j >= left && j<= right){
              while(j <= right){
                list.add(matrix[i][j]);
                j++;
              }
              j--;
              up++;
              i++;
            }else break;

            //下行到down边界，则right - 1
            if(i>= up && i<= down && j >= left && j<= right){
                while(i <= down){
                    list.add(matrix[i][j]);
                    i++;
                }
                i--;
                right--;
                j--;
            }else break;
            
            //左行到left边界，则down - 1
            if(i>= up && i<= down && j >= left && j<= right){
                while(j >= left){
                    list.add(matrix[i][j]);
                    j--;
                }
                j++;
                down--;
                i--;
            }else break;

            //上行到up边界，则left + 1
            if(i>= up && i<= down && j >= left && j<= right){
                while(i >= up){
                    list.add(matrix[i][j]);
                    i--;
                }
                i++;
                left++;
                j++;
            }else break;
        }
        return list;
    }
}
```