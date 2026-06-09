我自己想了一个比较嗨的想法，采用哈希桶的实现。

```
if (s==null||s.length()<=1)return s;
        int mod=numRows>2?numRows*2-2:numRows;  //规律，如果小于2的情况，则不需要考虑中间位置的字符//如果是需要考虑，这可以找出规律
        StringBuilder[] builders=new StringBuilder[numRows];
        for (int i=0;i<s.length();i++){
            int index=i%mod;
            if (index>=numRows){
                index=2*numRows-index-2;  //如果是中间位置的字符串，则对应桶的位置是按numRows-1中位映射对应
            }
            if (builders[index]==null)builders[index]=new StringBuilder();
            builders[index].append(s.charAt(i));
        }
        StringBuilder res=new StringBuilder();
        for (int i=0;i< numRows;i++){
               if(builder[i]!=null)
                    res.append(builders[i]);
        return res.toString();
```