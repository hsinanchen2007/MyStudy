    // 解决做某些事的先后次序
    class Solution {
        // 拓扑排序
        public boolean canFinish(int numCourses, int[][] prerequisites) {
            if(prerequisites.length == 0){
                return true;
            }
            int[] indegrees = new int[numCourses];
            for(int i = 0;i < prerequisites.length;i++) {  // 统计每个点的入度
                indegrees[prerequisites[i][0]]++;
            }
            Queue<Integer> queue = new LinkedList<>();
            for(int i = 0;i < numCourses;i++) {           // 入度为零的点入队
                if(indegrees[i] == 0) {                   // 即不需要先修其他课程的课先进入队列等待学习
                    queue.add(i);
                }
            }
            int learnCourses = 0;
            while(!queue.isEmpty()) {
                int course = queue.poll();
                learnCourses++;                 // 弹出一个先修课程都结束的课，开始学习
                for(int i = 0;i < prerequisites.length;i++) {
                    if(prerequisites[i][1] == course) {
                        indegrees[prerequisites[i][0]]--;
                        if(indegrees[prerequisites[i][0]] == 0) {
                            // 当前课入度为0了，可以开始学习了，加入到学习队列，等待学习
                            queue.add(prerequisites[i][0]);
                        }
                    }
                }
            }
            return learnCourses == numCourses;
        }
    }