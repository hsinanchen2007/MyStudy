class Logger {
public:
    map<string, int> mmap;

    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (mmap.find(message) == mmap.end() || timestamp - mmap[message] >= 10) {
            mmap[message] = timestamp;
            return true;
        }
        return false;
    }
};