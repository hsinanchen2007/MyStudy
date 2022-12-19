import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

class H2O {

    BlockingQueue<Integer> oQueue = new ArrayBlockingQueue<>(1);
    BlockingQueue<Integer> oQueueEnd = new ArrayBlockingQueue<>(2);
    BlockingQueue<Integer> hQueue = new ArrayBlockingQueue<>(2);
    BlockingQueue<Integer> hQueueEnd = new ArrayBlockingQueue<>(3);

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hQueue.put(1);
        releaseHydrogen.run();
        hQueueEnd.put(1);
        clearAllQueue();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oQueue.put(2);
        releaseOxygen.run();
        oQueueEnd.put(2);
        clearAllQueue();
    }

    public  void clearAllQueue(){

        if(hQueueEnd.size()== 2 && oQueueEnd.size() == 1){
            hQueueEnd.clear();
            oQueueEnd.clear();
            hQueue.clear();
            oQueue.clear();
        }
    }
}