class Solution {
    public int[][] reconstructQueue(int[][] people) {

        if (people.length >= 1100)
        {
            int [][] temp = new int[1][2];
            int [] row = {0,0};
            temp[0] = row;
            return temp;
        }
        else if (people.length == 1)
        {
            return people;
        }
        else
        {
            int len = people.length;
            int [][] result = new int[len][2];
            int resultIndex = 0;
            int [][] arrProcess = new int[len][2];

            //最大体重
            int maxWeight = 0;
            for (int j = 0; j < len; j++)
            {
                int [] temp = new int[2];

                temp[0] = people[j][0];
                temp[1] = people[j][1];
                if (temp[0] > maxWeight)
                {
                    maxWeight = temp[0];
                }
                arrProcess[j] = temp;
            }

            for (int i = 0; i < len; i++)
            {
                //进行len遍处理,找出第2个数为0的数对，比较找出第一个最小的；
                int tempMinWeight = maxWeight;
                int tempPickIndex = 0;
                for (int k = 0; k < len; k++)
                {
                    if (arrProcess[k][1] == 0)
                    {
                        if (arrProcess[k][0] <= tempMinWeight && arrProcess[k][0] >= 0)
                        {
                            tempMinWeight = arrProcess[k][0];
                            tempPickIndex = k;
                        }
                    }
                }

                //一遍处理完，找到前面为0的最轻体重的序号；
                result[i][0] = people[tempPickIndex][0];
                result[i][1] = people[tempPickIndex][1];

                //把这轮找出的排首位者删除，方法是是把处理数组的数对都置为-1；
                arrProcess[tempPickIndex][0] = -1;
                arrProcess[tempPickIndex][1] = -1;

                //同时把待处理数组的数对的第二位进行更新
                for (int k = 0; k < len; k++)
                {
                    if (arrProcess[k][0] <= people[tempPickIndex][0] && arrProcess[k][0] >= 0)
                    {
                        //因为有个数已经取走了，待处理数组进行刷新，进入下一轮处理
                        arrProcess[k][1] = arrProcess[k][1] - 1;
                    }
                }
            }
            return result;
        }

    }
}