select id,
    case
        when id in (select id from tree where p_id is null) then "Root"
        when id in (select p_id from tree) then "Inner"
        else "Leaf"
    end Type
from tree
order by id