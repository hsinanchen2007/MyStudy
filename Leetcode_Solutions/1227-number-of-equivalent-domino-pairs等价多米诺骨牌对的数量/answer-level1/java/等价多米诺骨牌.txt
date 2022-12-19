有点利用到了桶排序的思想。当dominoes[i]和dominoes[j]分别的两个数的和及差绝对值相等时，唯一确定他们等价。所以可以设置一个二维桶排序，行表示和，列表示差，然后遍历一遍后即可得到各唯一行和列有多少数，然后用a*(a-1)/2加起来即可。最后时间复杂度应该只有O(N),空间复杂度是O(1)。
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        //用桶排序，以a+b及a-b进行分桶
        int[][] bucket=new int[19][9];
        int count=0;
        for(int i=0;i<dominoes.length;i++){
            int sum=dominoes[i][0]+dominoes[i][1];
            int minus=Math.max(dominoes[i][1]-dominoes[i][0],dominoes[i][0]-dominoes[i][1]);
            bucket[sum][minus]++;
        }
        for(int i=2;i<19;i++){
            for(int j=0;j<9;j++){
                count+=bucket[i][j]*(bucket[i][j]-1)/2;
            }
        }
        return count;
    }
}