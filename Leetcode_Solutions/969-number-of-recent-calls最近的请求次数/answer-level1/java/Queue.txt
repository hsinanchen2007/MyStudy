class RecentCounter {

    Queue<Integer> queue = new LinkedList<Integer>();
    int THREEE_THOUSANDS = 3000;
    public RecentCounter() {
        
    }
    
    public int ping(int t) {
        
        queue.offer(t);
        
        while(queue.size() > 0) {
            if (queue.peek() < (t - THREEE_THOUSANDS)) {
                queue.poll();
            } else {
                break;
            }
        }

        return queue.size();
    }
}