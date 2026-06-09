### 解题思路
* 最关键是要将计数重置为1
* 循环次数要少一次，因为一开始没计算直接给Facade赋值了一个1

### 方法一 暴力计算法
```java
class Solution {
    public String countAndSay(int n) {        
        assert n >= 1;
        assert n <= 30;
        if(n == 1) {
            return "1";
        }
        List<Integer> facade = new ArrayList<>();
        facade.add(1);        
        for (int i = 1; i < n; i++) {
            int len = facade.size();            
            int anchor = facade.get(0);                      
            int anchorCnt = 1;
            List<Integer> newFacade = new ArrayList<>();            
            for(int read = 0; read < len; read++) {                                       
                int next = read+1 == len ? Integer.MAX_VALUE : facade.get(read+1);                               
                if(next == anchor) {
                    //针对anchor进行计数
                    anchorCnt++;                    
                } else {
                   // 结束计数
                    newFacade.add(anchorCnt);
                    newFacade.add(anchor);
                    //最关键一步是对计数进行重置
                    anchorCnt = 1;
                    anchor = next;
                }

            }//endfor
            facade.clear();
            //System.out.println(newFacade.toString());
            facade.addAll(newFacade);
        }//endfor
        StringBuilder sb = new StringBuilder();
        for(int item:facade){
            sb.append(item);
        }
        return sb.toString();
    }
}
```

### 方法二、递归计算
* 之所以写上是因为代码间接，但是效率真心不高，当做一个做题思考，万一时间紧急，也不错。
* 这个计算方法的美妙之处在于只考虑计算一个交换算法就可以了，真心简洁，但是不高效
```java
class Solution {
    public String countAndSay(int n) {        
        assert n >= 1;
        assert n <= 30;
        if(n==1) return "1";
        int count = 1;
        String res = "";
        String str = countAndSay(n-1);
        for(int i = 0, len = str.length(); i < len; i++){
            char next = i+1 == len ? ' ' : str.charAt(i+1);
            if(str.charAt(i) == next) {
                 //计算相同数字个数
                count++;                
            } else {
                res += count +""+ str.charAt(i);
                count=1;
            }
        }
       return res;
    }
}
```