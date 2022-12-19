class Solution {
    public int[] distributeCandies(int candies, int num_people) {
      int []result=new int [num_people];
        int candiescount=1;
        while(candies>0)
        {
            if(candiescount>candies)
            {
                result[(candiescount-1)%num_people]+=candies;
                candies=0;
            }
            else
            {
                result[(candiescount-1)%num_people]+=candiescount;
                candies=candies-candiescount;
                candiescount++;
            }
        }
        return  result;
}
}