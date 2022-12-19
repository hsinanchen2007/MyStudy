```
public int leastInterval(char[] tasks, int n) {
        int timeArr[] = new int [26];
        for (char c : tasks) {
            timeArr[c-'A']++;
        }

        Arrays.sort(timeArr);
        int maxTime = timeArr[25];
        int square = maxTime * (n+1);
        int rowCnt = 0;
        for (int x: timeArr) {
            square = square-x;
            if (x == maxTime )
                ++rowCnt;
        }

        if (square <=0)
            return tasks.length;
        return (n+1) * (maxTime-1) + rowCnt;
    }
```
