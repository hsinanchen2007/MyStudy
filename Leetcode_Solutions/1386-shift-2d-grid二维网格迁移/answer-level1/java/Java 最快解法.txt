![sss.png](https://pic.leetcode-cn.com/f5f3fca4646e3407d0f568b5f932ccbc0ef3781d46a2f22d02dda7d5cba8a295-sss.png)



思路： 将二维数组扁平化，直接跳转到移动k次后的相应下标，按照矩阵原来的长宽重新构建出答案。

代码：


  

     public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        int n = grid.length;
        int m = grid[0].length;//矩阵的长宽
        LinkedList<Integer> linkedList = new LinkedList<>();
        int x = 0;
        for (int[] ints : grid) {
            for (int j = 0; j < m; j++) {
                linkedList.add(ints[j]);
            }
        }//对矩阵进行扁平化操作，全塞进链表


        x = linkedList.size()-k%linkedList.size();//计算多次转移后，重构矩阵的下标
        List<List<Integer>> ans = new ArrayList<>();
        while (!linkedList.isEmpty()){
           List<Integer> list = new ArrayList<>();
           for (int i =0;i<m;i++){
               if (x>=linkedList.size()||x<0)x=0;//防止下标越界
               list.add(linkedList.get(x));
               linkedList.remove(x);
           }//根据矩阵的长宽来重组答案
              ans.add(list);
       }
            return ans;

    }



在数据存储方面，最开始想的是用数组（最简单），但如果是数组，重构矩阵在什么时候停下就很麻烦，因此采用的是链表的形式，其实也可以使用队列等方法


注意： 关于x（也就是重建矩阵的初始下标）的取值，  x = linkedList.size()-k%linkedList.size(); 不能直接用链表长度减去k，因为存在多次循环等情况，k可能是大于整个链表长度的，所以要先取余得到一个小于长度的真实下标

