```
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        /*List<Integer> res = new ArrayList<Integer>();
        int[] nums = new int[n];
        int min = Integer.MAX_VALUE;
        for(int i = 0; i<n; i++) {
            //探究以i为根节点的最大深度
            int[] visited = new int[n];
            int[] depth = new int[n];
            //看n个数是否都被访问过;首先初始化
            for(int j = 0; j<n; j++) {
                visited[j] = 0;
                depth[j] = Integer.MAX_VALUE;
            }
            depth[i] = 1;
            visited[i] = 1;
            //遍历edges 找到与i相连的 depth++;visited=1,跳出循环的条件：n个数全部被访问
            int sum = 1;
            while(sum<n) {
                for(int j = 0; j<edges.length; j++) {
                    if(visited[edges[j][0]]==1) {
                        if(visited[edges[j][1]]==0) {
                            sum++;
                            visited[edges[j][1]]=1;
                            depth[edges[j][1]] = Math.min(depth[edges[j][1]],depth[edges[j][0]]+1);
                            if(sum==n)
                                break;
                            continue;
                        }
                        else continue;
                    }
                    if(visited[edges[j][1]]==1) {
                        if(visited[edges[j][0]]==0) {
                            sum++;
                            visited[edges[j][0]]=1;
                            depth[edges[j][0]] = Math.min(depth[edges[j][0]],depth[edges[j][1]]+1);
                            if(sum==n)
                                break;
                            continue;
                        }
                        else continue;
                    }
                }
            }
            int tempmax = 0;
            for(int j = 0;j<n; j++) {
                if(depth[j]>tempmax)
                    tempmax = depth[j];
            }
            nums[i] = tempmax;
            if(nums[i]<min)
                min = nums[i];
        }
        for(int i = 0; i<n; i++) {
            if(nums[i]==min)
                res.add(i);
        }
        return res;*/
        //利用for循环遍历所有数字为根节点的做法会超时
        //选用别的方法
        /*
        执行用时 :152 ms, 在所有 Java 提交中击败了41.87%的用户内存消耗 :53.6 MB, 在所有 Java 提交中击败了78.08%的用户
        */
        int[] nums = new int[n];
        int[] flag = new int[n];
        for(int i = 0; i<n; i++) {
            flag[i] = 1;
        }
        int sum  = n;
        while(sum>2) {//剩余的数字大于2个 需要继续筛选
            for(int i = 0; i<nums.length; i++) {
                nums[i] = 0;
            }//初始化每个数字出现的次数为0
            for(int i = 0; i<edges.length; i++) {
                if(flag[edges[i][0]]==1 && flag[edges[i][1]]==1) {
                    //外层if的意思是：只有edge[i]的两个端点 同时有效 才对这条边进行统计
                    if(flag[edges[i][0]]==1)
                        nums[edges[i][0]]++;//出现次数+1
                    if(flag[edges[i][1]]==1)
                        nums[edges[i][1]]++;//出现次数+1
                }
            }
            for(int i = 0; i<n; i++) {
                if(nums[i] == 1) {
                    //如果出现次数为1（说明是叶子节点）置该位置无效（剔除该节点，flag[i]=0），sum--（sum为剩余数字个数）
                    sum--;
                    flag[i] = 0;
                }
            }
        }
        List<Integer> res = new ArrayList<Integer>();
        for(int i = 0; i<n; i++) {
            if(flag[i]==1)
            //找出剩下有效的1或2个数 加入到res中
                res.add(i);
        }
        return res;
    }
}
```
