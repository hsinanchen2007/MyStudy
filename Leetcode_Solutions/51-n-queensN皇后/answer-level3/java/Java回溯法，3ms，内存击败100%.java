把代码进行了模块化，更加清晰
直接上代码，注释已经写得很清楚了，有疑问或者建议欢迎评论
```java
// 回溯法
// 本质上采用和全排列一样的算法思想
// 只需要判断对角线是否有冲突：因为用mutate数组来模拟棋盘就已经确保了不会发生行冲突
// 而hashTable确保了不会发生列冲突
class Solution {
    private final List<int[]> positions = new ArrayList<>();
    private final List<List<String>> result = new ArrayList<>();
    private char[] template;
    
    public List<List<String>> solveNQueens(int n) {
        // hashTable用来标记某一列是否已经放置了皇后
        boolean[] hashTable = new boolean[n];
        // mutate用来存放可能的解决方案，数组索引等价于棋盘行，值等价于棋盘列
        int[] mutate = new int[n];
        recursively(n,mutate,hashTable,0);
        return result;
    }

    private void recursively(int n,int[] mutate,boolean[] hashTable,int layer){
        // layer代表着行，i代表着列
        if(layer==n){
            // 所有的皇后已经放置完毕，找到一种解决方案
            result.add(createPlan(mutate, n));
        }else{
            // 对于该行layer的每一列是否能放置皇后进行尝试
            for(int i=0;i<n;i++){
                // 如果在该列上还没有放置过皇后，并且假设在该行列（layer，i）上放置皇后不会与之前已经放置的皇后在对角线上发生冲突
                // 那么就放置下一行的皇后
                if(!hashTable[i]&&isDiagonalValid(mutate,layer,i,layer)){
                    hashTable[i]=true;
                    mutate[layer]=i;
                    // 放置下一行的皇后
                    recursively(n, mutate, hashTable, layer+1);
                    hashTable[i]=false;
                }
            }
        }
    }

    private List<String> createPlan(int[] mutate,int n){
        // 构造一种解决方案
        List<String> result = new ArrayList<>();
        initTemplate(n);
        for(int i=0;i<mutate.length;i++){
            template[mutate[i]] = 'Q';
            result.add(i,String.valueOf(template));
            template[mutate[i]] = '.';
        }
        return result;
    }

    private void initTemplate(int n){
        // 根据皇后个数来创建棋盘一行的模板
        if(template==null)template = new char[n];
        for(int i=0;i<n;i++){
            template[i]='.';
        }
    }

    private boolean isDiagonalValid(int[] mutate,int row,int column,int count){
        // 判断在（row,column）位置放置皇后是否会与之前已经放置的皇后的位置在一个对角线上
        for(int i=0;i<count;i++){
            int temp1=Math.abs(row-i),temp2=Math.abs(column-mutate[i]);
            if(temp1==temp2)return false;
        }
        return true;
    }
}
```
