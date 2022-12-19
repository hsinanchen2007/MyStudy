```
vector<int> distributeCandies(int candies, int num_people) {
        vector<int> tempArr(num_people, 0);
        int roundNum = 0;
        while(candies > 0)
        {
            for(int i = 0; i < num_people; i++)
            {
                int deltaNum = num_people*roundNum + i+1;
                if (candies <= deltaNum)
                {
                    deltaNum = candies;
                }
                
                tempArr[i] += deltaNum;
                candies -= deltaNum;
                if (candies <= 0)
                {
                    break;
                }
                
            }
            roundNum ++;
        };
        
        return tempArr;
    }
```
