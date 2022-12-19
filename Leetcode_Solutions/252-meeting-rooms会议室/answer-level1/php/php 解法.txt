```
function canAttendMeetings($intervals) {
    sort($intervals);
    $tmp = PHP_INT_MIN;
    foreach($intervals as $i){
        if($tmp > $i[0]) return false;
        $tmp = $i[1];
    }
    return true;
}
```
