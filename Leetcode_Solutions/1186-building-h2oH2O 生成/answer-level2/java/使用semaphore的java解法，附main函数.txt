
    public class H2O
    {
        
        public H2O()
        {
            
        }
        
        public static void main(String[] args) throws InterruptedException
        {
            final H2O h2o = new H2O();
            String input = "OOHHHH";
            char[] inputChar = input.toCharArray();
            for (int i = 0; i < inputChar.length; i++)
            {
                if (inputChar[i] == 'H')
                {
                    Thread threadA = new Thread() {
                        
                        @Override
                        public void run()
                        {
                            try
                            {
                                h2o.hydrogen(new Runnable() {
                                    
                                    @Override
                                    public void run()
                                    {
                                        System.out.print("H");
                                    }
                                });
                            }
                            catch (InterruptedException e)
                            {
                                e.printStackTrace();
                            }
                        }
                    };
                    threadA.start();
                }
                else
                {
                    Thread threadA = new Thread() {
                        
                        @Override
                        public void run()
                        {
                            try
                            {
                                h2o.oxygen(new Runnable() {
                                    
                                    @Override
                                    public void run()
                                    {
                                        System.out.print("O");
                                    }
                                });
                            }
                            catch (InterruptedException e)
                            {
                                e.printStackTrace();
                            }
                        }
                    };
                    threadA.start();
                }
            }
        }
        
        private Semaphore semaphoreH = new Semaphore(2);
        private Semaphore semaphoreO = new Semaphore(2);
        
        public void hydrogen(Runnable releaseHydrogen) throws InterruptedException
        {
            semaphoreH.acquire();
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            semaphoreO.release();
        }
        
        public void oxygen(Runnable releaseOxygen) throws InterruptedException
        {
            semaphoreO.acquire(2);
            // releaseOxygen.run() outputs "H". Do not change or remove this line.
            releaseOxygen.run();
            semaphoreH.release(2);
        }
    }