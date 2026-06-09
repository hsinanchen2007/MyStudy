执行用时 :2 ms, 在所有 Java 提交中击败了97.76%的用户
内存消耗 :36 MB, 在所有 Java 提交中击败了100.00%的用户

思路：
1、先把每个人去A的费用减去每个人去B的费用存入一个数组vals，并将所有人去B的费用加到result
2、将vals排序
3、将vals中前一半数据加到result中
4、返回result

排序选用的归并排序，排序速度较快。



    public int twoCitySchedCost(int[][] costs) {
        int[] vals=new int[costs.length];
        int i;
        int result=0;
        for(i=0;i<costs.length;i++){
            vals[i]=costs[i][0]-costs[i][1];
            result+=costs[i][1];
        }
        sort(vals,0,costs.length-1);
        for(i=0;i<costs.length/2;i++){
            result+=vals[i];
        }
        return result;
    }
    public int[] sort(int a[],int l,int r){
        if(l==r)
            return a;
        a=sort(a,(l+r)/2+1,r);
        a=sort(a,l,(l+r)/2);
        int[] templ=new int[(l+r)/2-l+1];
        int[] tempr=new int[r-(l+r)/2];
        int i;
        int tl=0;
        for(i=l;i<=(l+r)/2;i++){
            templ[tl++]=a[i];
        }
        int tr=0;
        for(i=(l+r)/2+1;i<=r;i++){
            tempr[tr++]=a[i];
        }
        int p=r;
        tl--;
        tr--;
        while(tl!=-1||tr!=-1){
            if(tl==-1){
                a[p]=tempr[tr];
                tr--;
            }
            else if(tr==-1){
                a[p]=templ[tl];
                tl--;
            }
            else if(tempr[tr]>templ[tl]){
                a[p]=tempr[tr];
                tr--;
            }
            else{
                a[p]=templ[tl];
                tl--;
            }
            p--;
        }
        return a;
    }
