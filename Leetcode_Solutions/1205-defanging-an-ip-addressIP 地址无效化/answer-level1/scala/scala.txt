写个regex，直接用replacerAllIn方法，两段话搞定。消耗内存43.2MB


def defangIPaddr(address: String): String = {
    val regex="[.*]".r
    regex.replaceAllIn(address,"[.]")
 }