```
class Logger {
    function __construct() {
        $this->map = [];
    }
    function shouldPrintMessage($timestamp, $message) {
        if(isset($this->map[$message]) && $timestamp - $this->map[$message]<10) return false;
        $this->map[$message] = $timestamp;
        return true;
    }
}
```
