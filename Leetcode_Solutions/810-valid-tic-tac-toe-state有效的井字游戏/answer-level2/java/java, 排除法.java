本题没有什么好的技巧，就是把不符合要求排除了，剩余都是正确的，思路：
1，先下X，再下O，轮询着来，意味着，X数量一定和O的数量相同或者大于1，不符合直接返回false；
2，如果出现3个X连在一起，满足结束条件，这时候，X数量减去O的数量一定为1，不符合直接返回false；
3，如果出现3个O连在一起，满足结束条件，这时候，X数量减去O的数量一定为0，不符合直接返回false；


class Solution {
    public boolean validTicTacToe(String[] board) {
        int xn = 0;
        int on= 0;
        List<String> list = new ArrayList<String>();
        String[][] nums = new String[3][3];
        int index =0;
        for(String word : board)
        {
            list.add(word);
            String[] chars = word.split("");
            int j = 0;
            for(String cha : chars)
            {
                nums[index][j] = cha;
                if(cha.equals("X"))
                {
                    xn++;
                }else if (cha.equals("O"))
                {
                    on++;
                }
                j++;
            }
            index++;
        }
        int value = xn-on;
        if (value<0 || value>1)
        {
            return false;
        }
        for (int i =0;i<3;i++)
        {
            String ab = "";
            for (int j =0;j<3;j++)
            {
                ab = ab + nums[j][i];
            }
            list.add(ab);
        }
        list.add(nums[0][0] + nums[1][1] + nums[2][2]);
        list.add(nums[0][2] + nums[1][1]+nums[2][0]);
        int threeX = 0;
        int threeO = 0;
        for(String word : list)
        {
            if (word.equals("XXX"))
            {
                threeX++;
            }else if (word.equals("OOO"))
            {
                threeO++;
            }
        }
        if (threeX!=0 && value!=1)
        {
            return false;
        }
        if (threeO!=0 && value!=0)
        {
            return false;
        }
         return true;
    }
}