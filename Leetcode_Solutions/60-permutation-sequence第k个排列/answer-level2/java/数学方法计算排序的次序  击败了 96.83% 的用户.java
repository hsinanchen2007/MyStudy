
    int[] u;
    public String getPermutation(int n, int k) {
        //想法是 先找第一个数 再找第二个数字。。。。 按照从小到大的顺序
        u = new int[n];
        ArrayList<Integer> use = new ArrayList();
        int ans = 1;
        for(int i=1;i<=n;i++){
            use.add(i);
            u[i-1]=ans; //计算n! 并且保存
            ans*=i;
        }
        return find(n,1,0,k,use,"");
    }
    public String  find(int n,int index, int now,int k, ArrayList<Integer> use,String ans){
        int temp = u[n-index];
        for(int i=0 ; i < use.size();i++){      
            if(now + (i+1) * temp > k ){                
                ans = ans + use.get(i);
                use.remove(i);
                return find(n,index+1,now + i * temp,k, use, ans);
            }else if(now + (i+1)  * temp == k ){ //use中的数字由大到小全排列
                ans+=use.get(i); use.remove(i); //加入第i个数字 然后删除
                //选定了之后 以后的数都是从最大到最小来进行全排序的 这样才能让可能的数量最大化
                for(int j=use.size()-1;j>=0;j--) ans+=use.get(j);
                return ans;
            }
        }
        return "";
    