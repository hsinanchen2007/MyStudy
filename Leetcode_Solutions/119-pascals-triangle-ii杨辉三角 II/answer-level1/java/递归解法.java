在上一层的基础上获取新数组
```
public static List<Integer> getRow(int rowIndex) {
        rowIndex ++;
        List<Integer> result = new ArrayList<Integer>();
        if(rowIndex ==1 || rowIndex ==2){
            for (int i = 0 ;i <rowIndex;i++){
                result.add(1);
            }
        }else {
            result = getRows(rowIndex);
        }

        return result;
    }

    //递归解法
    public static List<Integer> getRows(int k){
        List<Integer> result = new ArrayList<Integer>();
        if(k ==1 || k ==2){
            for (int i = 0 ;i <k;i++){
                result.add(1);
            }
        }else{
            List<Integer> tempResult  = getRows(k-1);
            //第一位
            result.add(1);
            for (int i = 1;i<tempResult.size();i++){
                result.add(tempResult.get(i)+tempResult.get(i-1));
            }
            //最后一位
            result.add(1);
        }

        return result;
    }
```
