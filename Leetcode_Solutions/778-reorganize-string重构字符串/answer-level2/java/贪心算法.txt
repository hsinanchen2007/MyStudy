每次输出剩余数量最多和次多的字符,可利用数组重写排队器来排序.

```
class Solution {
    HashMap<Character,Integer> data=new HashMap<>();
    public String reorganizeString(String S) {
        for (char c : S.toCharArray()) {
            data.put(c, data.getOrDefault(c, 0)+1);
        }
        int da[][]=new int[data.size()][2];
        int i=0;
        for (Map.Entry<Character, Integer> entry : data.entrySet()) {
            da[i++]=new int[]{entry.getKey(),entry.getValue()};
        }
        if (da.length<2)
            return "";
        StringBuffer stringBuffer=new StringBuffer();
        sortint(da);
        while (da[0][1]!=0){
            stringBuffer.append((char)da[0][0]);
            da[0][1]--;
            if (da[1][1]==0){
                sortint(da);
                break;
            }
            stringBuffer.append((char)da[1][0]);
            da[1][1]--;
            sortint(da);
        }
        if (da[0][1]!=0)
            return "";
        return stringBuffer.toString();


    }
    private void sortint(int[][] da){
        Arrays.sort(da,new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2) {
                return o2[1]-o1[1];
            }
        });
    }
}
```
