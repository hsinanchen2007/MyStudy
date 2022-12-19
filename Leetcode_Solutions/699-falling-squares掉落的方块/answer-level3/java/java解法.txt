执行用时 :62 ms, 击败了83.33%的用户。
内存消耗 :44 MB, 击败了100.00%的用户。
```
class Solution {    
     public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> hList = new ArrayList<>();//存放当前方块的高度
        List<Integer> list = new ArrayList<>();//存放当前最大高度
        if(positions == null || positions.length == 0){
            return list;
        }
        int maxH = positions[0][1];
        int high = positions[0][1];
        hList.add(high);
        list.add(maxH);
        P:for(int i = 1; i < positions.length; i++){
            high = positions[i][1];
            //判断当前方块能否放在之前的方块上方，并取得最高值
            for(int j = i-1; j>=0; j--){
                if(!(positions[j][0] >= positions[i][0] + positions[i][1] || positions[j][0] +positions[j][1]<=  positions[i][0])){
                    int temp = hList.get(j) + positions[i][1];
                    if(temp > high){
                        high = temp;
                    }
                }
            }
            hList.add(high);
            if(high > maxH){
                maxH = high;
            }
            list.add(maxH);
        }
        return list;
    }
}
```