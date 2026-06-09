```
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer integer, Integer t1) {
                return t1 - integer;
            }
        });
        for (int i = 0 ; i < matrix.length; i++){
            for (int j = 0; j < matrix[0].length; j++){
                queue.add(matrix[i][j]);
                if (queue.size() > k)
                {
                    queue.poll();
                }

            }

        }
        return queue.peek();
    }
```
正常优先级队列是小顶堆，重写下比较方法变为大顶堆。