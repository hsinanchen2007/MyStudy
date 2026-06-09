class Solution {
    int[] hasFriend;
    int[][] Matrix;
    int length;
    int count=0;
    int num=0;
    public int findCircleNum(int[][] M) {
        hasFriend=new int[M.length];
        Arrays.fill(hasFriend,-1);
        Matrix=M;
        length=M.length;
        for(int i=0;i<length;i++){
            if(hasFriend[i]==-1) {helper(i);if(count>0) num++;}
        }
        return num;
    }
    public void helper(int N){
        boolean hasChild=false;
        hasFriend[N]=1;
        for(int i=0;i<length;i++){
            if(Matrix[N][i]==1&&N!=i&&hasFriend[i]==-1){hasFriend[i]=1;hasChild=true;helper(i);}
        }
        if(!hasChild) count++;
    }
}![截屏2019-10-24下午2.37.56.png](https://pic.leetcode-cn.com/4418affb552e33fde723540a1c8a2f8286efc6dfb61ae7ce8b5163f312637d5f-%E6%88%AA%E5%B1%8F2019-10-24%E4%B8%8B%E5%8D%882.37.56.png)
