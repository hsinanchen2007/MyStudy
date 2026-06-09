1. 当我们观察这个矩阵的时候，我们会发现一个很有意思的事情，假设i,j是一个矩阵的坐标值，我们很容易就可以得出比matrix[i][j]大一点点的值在哪，毫无疑问是matrix[i+1][j]和matrix[i][j+1].
2. 由上面我们的观察我们虽然明白了一个坐标的下右比这个坐标值要大，但我们不知道的是下面右边谁比较大，要解决这个问题，我们引入了堆，由它帮我们找到这个最小值。
3. 我们在每次拿到堆的最小值坐标时，我们能不能把右边下边都加入堆呢仔细想想是不可以的，这样会造成重复加入，那么解决问题的方法也很简单，我们可以先把一行加入堆然后接下来每次都将下一行的值加入堆，这样就避免了重复问题
4. 这种方法的效率是不如二分的，但是这样方法非常易懂，且能够得到更多的信息，就是说我们能得到每一个最小值的坐标，以及这个序列
5. 最后我们贴上代码，欢迎大家讨论
```
public int kthSmallest(int[][] matrix, int k) {
        int x = matrix.length;
        int y = matrix[0].length;
        PriorityQueue<int[]> queue = new PriorityQueue<>((v1,v2)->v1[2]-v2[2]);
        for(int j = 0; j < y; j++) queue.offer(new int[]{0, j, matrix[0][j]});
        int[] v = new int[]{0, 0, -1};
        while(!queue.isEmpty() && k > 0){
                k--;
                v = queue.poll();
                if(v[0] + 1 < x) queue.offer(new int[]{v[0]+1, v[1], matrix[v[0]+1][v[1]]});
        }
        return v[2];
}
```
