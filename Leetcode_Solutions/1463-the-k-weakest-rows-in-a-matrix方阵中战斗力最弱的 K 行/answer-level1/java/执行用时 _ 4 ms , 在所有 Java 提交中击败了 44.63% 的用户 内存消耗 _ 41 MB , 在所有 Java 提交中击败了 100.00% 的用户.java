### 解题思路
1. 先递归查找每行的士兵数，存入temp数组
2. 复制一个sort数组对temp排序
3. 查找sort数组的前k个的值在temp数组中的位置，temp数组的下标即为答案，存入list，因为每行可能存在相同的士兵数，所以要进行一个判断，排除重复存入同一个temp下标
4. 最后从list中存入ans数组，输出。

### 代码

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] temp = new int[mat.length]; //存放每一行的士兵数
        int[] ans = new int[k];           //存放答案的数组
        for(int i = 0;i<mat.length;i++){
            int count = 0;
            for(int j = 0;j<mat[0].length;j++){
                if(mat[i][j]  != 1){
                    break;
                }
                count++;
            }
            temp[i] = count;
        }
        int[] sort = temp.clone();
        Arrays.sort(sort);                     // 排序
        List<Integer> list = new ArrayList<>();//根据排完序的数组sort查找temp对应的下标
        for(int i = 0;i<k;i++){                //存入list，排除具有相同士兵数的不同行
            for(int j = 0;j<temp.length;j++){
                if(sort[i] == temp[j]){
                    if(!list.contains(j)){
                        list.add(j);
                        break;
                    }
                }
            }
        }
        for(int i = 0;i<list.size();i++){     //存入ans数组并返回
            ans[i] = list.get(i);
        }
        return ans;
    }
}
```