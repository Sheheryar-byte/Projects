
function Celsius(input){
    return (input - 32) * (5/9);
}

function Farenheit(input){
    return input * 9/5 + 32;
}

document.getElementById("sbtn").onclick = function(){

    let input;

    if(document.getElementById("crad").checked){
        input = document.getElementById("num").value;
        input = Celsius(input);
        input = document.getElementById("lab").innerHTML = input;

    }

    if(document.getElementById("frad").checked){
        input = document.getElementById("num").value;
        input = Farenheit(input);
        input = document.getElementById("lab").innerHTML = input;
    }
    



}