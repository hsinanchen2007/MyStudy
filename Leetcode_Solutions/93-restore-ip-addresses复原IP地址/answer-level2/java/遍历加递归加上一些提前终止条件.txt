提交结果：
执行用时 :3 ms, 在所有 Java 提交中击败了95.80% 的用户
内存消耗 :36.4 MB, 在所有 Java 提交中击败了46.60%的用户

思路：递归每次获取一段，获取每一段时都遍历，因为每一段都可能是1到3个长度。
     然后有一些提前终止的条件，包括：1.获取了某一段，它的值大于255或者长度大于1但是不为0
                                    2.剩下的长度不够后面的人分，或者没人三个数字还有剩余
                                        3.剩下的长度不够该段（特指最后一段）


代码：
```
public List<String> restoreIpAddresses(String s) {
        List<String> res=new ArrayList<>();
        getNext(res,new StringBuilder(),s,0,4);//获取第一段
        return res;
    }

    private void getNext(List<String> res, StringBuilder sb, String s,int begin, int n) {
        if (n==0){
            if(begin==s.length())
                res.add(sb.toString());//唯一的入列条件
            else return;
        }
       if (s.length()-begin<n||s.length()-begin>n*3)return ;//长度太小或者太大
        for (int i = 3; i >0; i--) {
            if (begin+i<=s.length()){//下标不能越界
                String substring = s.substring(begin, begin + i);
                //以0开头但是长度不为1或者数值大于255 错误
                if ((substring.charAt(0)=='0'&&i!=1)||(Integer.valueOf(substring)>255))continue;
                StringBuilder tmp=new StringBuilder(sb);
                if (n==4)tmp.append(substring);
                else tmp.append(".").append(substring);
                getNext(res,tmp,s,begin+i,n-1);//获取下一段
            }
        }
    }
```
