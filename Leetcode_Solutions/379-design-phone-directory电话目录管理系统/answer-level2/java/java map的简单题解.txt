public class PhoneDirectory {

    private Map<Integer, Boolean> phoneNumMap = null;

    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    public PhoneDirectory(int maxNumbers) {
        phoneNumMap = new HashMap<>();
        for (int i = 0; i < maxNumbers; i++) {
            phoneNumMap.put(i, false);
        }
    }

    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    public int get() {
        for (Map.Entry<Integer, Boolean> entry : phoneNumMap.entrySet()) {
            if (!entry.getValue()) {
                phoneNumMap.put(entry.getKey(), true);
                return entry.getKey();
            }
        }
        return -1;
    }

    /** Check if a number is available or not. */
    public boolean check(int number) {
        return !phoneNumMap.get(number);
    }

    /** Recycle or release a number. */
    public void release(int number) {
        phoneNumMap.put(number, false);
    }
}