# 第一次的思维
```java
/**
     * 自解-虽然是对的，但是完全没有考虑其他的问题，代码冗长
     * 由于没有考虑，最后的进位该如何处理，最开始的想法只能是这样
     */
    public String addBinary(String a, String b) {
        int alen=a.length(),blen=b.length(),len,sublen;
        char[] ans;
        if(alen<blen){//len表示较长，同时生成char[]，sublen表示较短的
            sublen=alen;
            len=blen;
            ans=b.toCharArray();
        }else{
            sublen=blen;
            len=alen;
            ans=a.toCharArray();
        }
        boolean propagation=false;
        for(int i=len-1;i>=0;i--){
            while(--sublen>=0){
                char l=a.charAt(--alen),r=b.charAt(--blen);
                propagation=propagation(ans,i,l,r,propagation);
                i--;
            }
            if(i<0){//可能长度相等
                break;
            }
            propagation=propagation(ans,i,ans[i],'0',propagation);
            if(!propagation&&i>0){//可能无需最后的进位
                break;
            }
        }
        StringBuilder sb=new StringBuilder();
        if(propagation){
            char[] x=new char[len+1];
            x[0]='1';
            System.arraycopy(ans,0,x,1,len);
            ans=x;
        }
        for(char cc:ans){
            sb.append(cc);
        }
        return sb.toString();
    }

private boolean propagation(char[] ans,int i, char l, char r, boolean propagation) {
        if(l!=r){
            if(propagation){
                ans[i]='0';
            }else{
                ans[i]='1';
            }
        }else if(l=='0'){//相等
            if(propagation){
                ans[i]='1';
            }
            propagation=false;
        }else{//1
            if(propagation){
                ans[i]='1';
            }else{
                ans[i]='0';
            }
            propagation=true;
        }
        return propagation;
    }
```

# 第二次的思维
```java
/**
     * 自解-减少冗余代码
     * 1、不关心a,b的长短，将a或b用完，再接着用a或b
     * 2、利用StringBuilder的append，然后反转字符串即可。
     *  但是总觉得propagation方法太长
     */
    public String addBinaryOptimize(String a, String b) {
        int alen=a.length(),blen=b.length();
        StringBuilder sb=new StringBuilder();
        boolean propagation=false;
        while(alen>0||blen>0){
            propagation=propagation(sb,alen>0?a.charAt(--alen):'0',blen>0?b.charAt(--blen):'0',propagation);
        }
        if(propagation){
            sb.append('1');
        }
        return sb.reverse().toString();
    }

    private boolean propagation(StringBuilder sb, char l, char r, boolean propagation) {
        if(l!=r){
            if(propagation){
                sb.append('0');
            }else{
                sb.append('1');
            }
        }else if(l=='0'){//相等
            if(propagation){
                sb.append('1');
            }else{
                sb.append('0');
            }
            propagation=false;
        }else{//1
            if(propagation){
                sb.append('1');
            }else{
                sb.append('0');
            }
            propagation=true;
        }
        return propagation;
    }
```
# 第三次的思维
```java
/**
     * 自解-减少冗余代码，代价就是代码可读性变低
     * 1、不关心a,b的长短，将a或b用完，再接着用a或b
     * 2、利用StringBuilder的append，然后反转字符串即可。
     * 缩减propagation方法
     * l r  | res propagation
     *  0 0  0  1  0
     *  0 1  1  0  1
     *  1 0  1  0  1
     *  1 1  0  1  1
     */
    public String addBinaryOptimizeDouble(String a, String b) {
        int alen=a.length(),blen=b.length();
        StringBuilder sb=new StringBuilder();
        boolean propagation=false;
        while(alen>0||blen>0){
            char l=alen>0?a.charAt(--alen):'0';
            char r=blen>0?b.charAt(--blen):'0';
            if(l!=r){
                sb.append(propagation?'0':'1');
            }else{//1 , 0
                sb.append(propagation?'1':'0');
                propagation= l == '1';
            }
        }
        if(propagation){
            sb.append('1');
        }
        return sb.reverse().toString();
    }
```
