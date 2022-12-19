****
```
  public int minTimeToVisitAllPoints(int[][] points) {
       int answer = 0;
        for (int i = points.length - 1; i >= 1; i--) {
            answer += Math.max(Math.abs(points[i][0] - points[i-1][0]),Math.abs(points[i][1] - points[i-1][1]));
        }
        return answer;
    }
```
