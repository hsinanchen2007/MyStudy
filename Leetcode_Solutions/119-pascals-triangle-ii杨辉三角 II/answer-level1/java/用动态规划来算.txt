找到状态之间的关系后，可以使用两行，也可以只是用1行数组本身（需要2辅助变量）。
```
class Solution {
    public List<Integer> getRow(int rowIndex) {
        if(rowIndex <0)
            return Collections.emptyList();
        
        if(rowIndex==0){
            List<Integer> line1 = new LinkedList<>();
            line1.add(1);
            return line1;
        }else if(rowIndex ==1){
            List<Integer> line2 = new LinkedList<>();
            line2.add(1);
            line2.add(1);
            return line2;
        }

        Integer[] line = new Integer[rowIndex+1];
        Arrays.fill(line, 0);
        line[0]=1;
        line[1]=1;
        
        for(int j=2;j<=rowIndex; j++){
            int preI_1 = line[0];
            int preI = line[1];
            
            for(int i=1;i<j;i++){
                line[i]=(preI_1+ preI);
                preI_1 = preI;
                preI = line[i+1];
            }
            
            line[j]=1;
        }
        
        return Arrays.asList(line);
    }

}
```