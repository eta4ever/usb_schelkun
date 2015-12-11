$fa=5; $fs=0.1;

intW=26;
intL=50;
intH=13;
wall=2;

// корпус
difference(){
    union(){
        cube([intW+2*wall, intL+2*wall, intH+wall]); //наружнее
    }
    
    union(){
        translate([wall,wall,wall]) cube([intW, intL, intH]); // вырез
        translate([3.5+wall, 0, 3.5+wall]) cube([14.5, wall, intH-3.5]); // USB F
        translate([4.25+wall, intL+wall, 3.5+wall])  cube([12.5, wall, intH-3.5]); // USB M
    }
}    

// крышка
translate([intW+2*wall+10, 0,0]) {
    
    cube([intW+2*wall, intL+2*wall, wall]); // плоскость
    translate([4.25+wall, 0, wall])  cube([12.5, wall, intH-3.5-5.5]);// USB M
    translate([3.5+wall, intL+wall, wall]) cube([14.5, wall, intH-3.5-7]); // USB F
    
}
