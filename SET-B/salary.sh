read -p "Enter Salary: " salary

ta=$(echo "scale=4; 0.5/100*$salary" | bc)
da=$(echo "scale=4; 10/100*$salary" | bc)
hra=$(echo "scale=4; 10.5/100*$salary" | bc)

echo "TA: $ta"
echo "DA: $da"
echo "HRA: $hra"

total=$(echo "scale=4; $salary+$ta+$da+$hra" | bc)

epf=$(echo "scale=4; 12.5/100*$total" | bc)
esi=$(echo "scale=4; 2.5/100*$total" | bc)

echo "EPF: $epf"
echo "ESI: $esi"

net=$(echo "scale=4; $total-$epf-$esi" | bc)

echo "Total: $total"
echo "Net Salary: $net"