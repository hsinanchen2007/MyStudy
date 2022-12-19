### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int expressiveWords(String S, String[] words) {
       List<Num> lis=jianhua(S);
        int count=0;
        for(int i=0;i<words.length;i++){
      List<Num> lis2=jianhua(words[i]);
            if(iskekuangzhang(lis,lis2))
                count++;
        
        }
        return count;
    }
   public boolean  iskekuangzhang( List<Num> lis, List<Num> lis2){
       if(lis.size()!=lis2.size())
            return false;
        
        for(int i=0;i<lis.size();i++){
            Num num1=lis.get(i);
            Num num2=lis2.get(i);
     
            if(num1.a!=num2.a)
                return false;
            if(num1.b<num2.b){
                return false;
            }
            else if(num1.b==num2.b){

            }else if(num1.b<3&&num1.b-num2.b<2){
                return false;
            }else{}
        }
        return true;

   }
    public List<Num> jianhua(String s){
        ArrayList<Num> list=new ArrayList<>();
        char initchar=s.charAt(0);
		int count=1;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)==initchar){
                count++;
            }else{
                Num num=new Num(initchar,count);
                list.add(num);
                initchar=s.charAt(i);
                count=1;
            }

        } 
        Num num=new Num(initchar,count);
        list.add(num);
        return list;
    }
    class Num{
        char a;
        int b;
        public Num(char a,int b){
            this.a=a;
            this.b=b;
        }
    }
}
```