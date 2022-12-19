一开始想是两层循环，后发现不是这样的问题。
```
    class Solution {
        List<String> list=new ArrayList<String>();
        String[] z={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        public List<String> letterCombinations(String digits) {
            if(digits==null||digits.length()==0){
                return list;
            }
            append(digits,"");
            return list;
        }
        public void append(String num,String now){
            if (num.length()==0){
                list.add(now);
            }
            else {
                int m=num.charAt(0)-'0';
                int loop=3;
                if (m==7||m==9) loop=4;
                for (int i=0;i<loop;i++){
                    append(num.substring(1,num.length()),now+z[m-2].charAt(i));
                }
            }
        }    
    }
```
这个题目相当于一棵树，每层都寻找可以走的道路。使用递归解决问题。
