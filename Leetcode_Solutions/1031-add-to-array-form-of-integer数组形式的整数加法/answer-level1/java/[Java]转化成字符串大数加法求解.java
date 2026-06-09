**思路** 

Java实现思路：转化成两个String类型的数字后，用大数加法实现，最后再转成整型列表返回即可

**代码**

```C++ []
public List<Integer> addToArrayForm(int[] A, int K) {
        //考虑溢出情况，需要按位模拟
        //都转成字符串，用大数加法完成
        
        //转字符串
        StringBuilder a = new StringBuilder();
        for(int i=0; i<A.length; i++) {
            a.append(A[i]);
        }
        String b = String.valueOf(K);
        //大数加法
        String resultStr = addStrNum(a.toString(), b);
        //字符串结果转数组
        return strToIntegerList(resultStr);
    }
    
    public String addStrNum(String a, String b) {
        String reA = new StringBuilder(a).reverse().toString();
        String reB = new StringBuilder(b).reverse().toString();
        
        int indexA = 0;
        int indexB = 0;
        
        int lengthA = a.length();
        int lengthB = b.length();
        
        StringBuilder result = new StringBuilder();
        int carry = 0;
        
        while(indexA<lengthA || indexB<lengthB) {
            int valA = indexA<lengthA? Integer.valueOf(String.valueOf(reA.charAt(indexA))) : 0;
            int valB = indexB<lengthB? Integer.valueOf(String.valueOf(reB.charAt(indexB))) : 0;
            
            result.append((valA+valB+carry)%10);
            
            carry = (valA+valB+carry)/10;
            
            indexA++;
            indexB++;
        }
        if(carry>0) {
            result.append(carry);
        }
        return result.reverse().toString();
    }
    
    public List<Integer> strToIntegerList(String str) {
        List<Integer> list = new ArrayList();
        for(int i=0; i<str.length(); i++) {
            list.add(Integer.valueOf(String.valueOf(str.charAt(i))));
        }
        return list;
    }
```