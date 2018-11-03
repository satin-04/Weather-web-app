<!DOCTYPE html>
<html lang="en" >

<head>

    <meta charset="UTF-8">
    <title>WeatherIO</title>
    <link rel="shortcut icon" type="ico" href="favicon.ico"/>
    <script src="https://ajax.googleapis.com/ajax/libs/angularjs/1.7.5/angular.min.js"></script>
    <!--<meta name="viewport" content="width=device-width, initial-scale=1.0">-->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <style>
        @import url('https://fonts.googleapis.com/css?family=Roboto|Krub|ABeeZee|Comfortaa');
        @import url('https://fonts.googleapis.com/css?family=Andada|Permanent+Marker|Raleway:300');

        * {
            box-sizing: border-box;
        }

        html {
            margin: 0;
            -webkit-tap-highlight-color: rgba(0,0,0,0);
            -webkit-tap-highlight-color: transparent;
            height : 100%;
        }

        body {
            /*background-attachment: fixed;*/
            margin : 0px;

            height : 100%;
            background: #000428;  /* fallback for old browsers */
            background: -webkit-linear-gradient(to right,#004e92, #000428);  /* Chrome 10-25, Safari 5.1-6 */
            background: linear-gradient(to right,#004e92, #000428); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */
            position: relative;
            font-family: 'Roboto', sans-serif;
            color: #fff;
        }


        #Header {
            margin-top: 50px;
            text-align: center;
            font-size: 30px;
            color: rgba(250,250,250,1);
            font-family: 'Comfortaa', cursive;
            cursor: pointer;
            /*background: #00c4cc linear-gradient(139deg, #00c4cc 0, #7d2ae8 100%);*/

        }

        #box {
            width:50%;
            height:50%;
            margin:0 auto;
            border-radius: 99px;
            text-align: center;
        }

        button {
            padding-top:0;
            background: #004e92;
            outline: none;
            border: 0px;
            color: #fff;
            font-size: 20px;
            cursor: pointer;
            width: 100%;
            height:100%;
        }

        #address {
            font-family: 'ABeeZee', sans-serif;
            font-size: 30px;
        }

        .temp {
            margin-top: 30px;
            margin-bottom: 40px;
            font-size: 85px;
            cursor: pointer;
        }

        #deg {
            font-size: 30px;
        }

        #status {
            font-size : 25px;
            text-align: center;
            display: inline-block;
            margin: 40px 200px 20px 200px;
        }
        /*h1 {*/
        /*margin-top : 0;*/
        /*}*/

        #error {
            font-size: 25px;

        }

        #predict {
            font-size: 20px;
            margin: 40px 0  20px 0;
        }

        #humidity {
            margin: 40px 200px 20px 0;
            font-size : 25px;
            float: right;
            text-align: center;
            display: inline-block;

        }

        #pressure {
            margin: 40px 0  20px 200px;
            float:left;
            font-size : 25px;
            text-align: center;
            display: inline-block;
        }
        #pressure, #humidity, #status {

            z-index: 1;
            background: #107DAC;  /* fallback for old browsers */
            /*background: -webkit-linear-gradient(to right, #A6FFCB, #12D8FA, #1FA2FF);  !* Chrome 10-25, Safari 5.1-6 *!*/
            /*background: linear-gradient(to right, #A6FFCB, #12D8FA, #1FA2FF); !* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ *!*/

            /*position: relative;*/
            display: inline-block;
            border-radius: 20px;
            width: 25%;
            height: 20%;
            box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19);
            /*padding: 20px 38px 100px 38px;*/
            margin: 10% auto ;
            /*margin: 10px;*/
        }


        #predict_content {
            font-size: 20px;
            margin: 40px 0  20px 0;
        }

        #predict {
            z-index: 1;
            background: #107DAC;  /* fallback for old browsers */
            /*background: -webkit-linear-gradient(to right, #A6FFCB, #12D8FA, #1FA2FF);  !* Chrome 10-25, Safari 5.1-6 *!*/
            /*background: linear-gradient(to right, #A6FFCB, #12D8FA, #1FA2FF); !* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ *!*/

            /*position: relative;*/
            display: inline-block;
            border-radius: 20px;
            width: 100%;
            height: 40%;
            box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19);
            /*padding: 20px 38px 100px 38px;*/
            margin: 10% auto ;
            /*margin: 10px;*/
        }


    </style>
    <script>
        $(document).ready(function(){
            $("body").delay("slow").fadeIn();
        })
    </script>


    <script type="text/javascript">

        var app=angular.module("app",[]);
        app.controller("emp",['$scope',function($scope){
            $scope.iconi='{{icon}}';
            $scope.tempF = '{{tempF}}';
            $scope.tempC = '{{tempC}}';
            $scope.predict = "{{predict}}";

            $scope.count = 1;
            $scope.bool = 'true';
            $scope.display = function () {
                $scope.count++;
                if($scope.count%2==0){
                    $scope.bool='false';
                }
                else {
                    $scope.bool = 'true';
                }
            };
            $scope.error = '{{error}}';
            $scope.wind = '{{wind}}';
            $scope.humidity = '{{humidity}}';
            $scope.url = '{{url}}';

        }]);
    </script>
</head>



<body>
<form action="/">
    <!--<span id="logo"><img src="logo.svg" style="margin-top: 23px;margin-left: 50px;width:80px;height: 80px"></span>-->
    <button style=" background: transparent !important" type="submit"><div id="Header"><h1><b>Weather.IO</b></h1></div></button>
</form>

<div ng-app="app">
    <div ng-controller="emp">

        <div id="box" style="width: 90%; margin-top: 4%;">
            <div id="table" >
                <a style="color: white;  text-decoration: none;" target="_blank" href="https://www.google.com/search?num=100&newwindow=1&safe=active&q={{url}}"><p id="address">{{street}}{{area5}}{{state}}{{country}}</p></a>
                <span ng-if="error==''" style="margin-bottom: 5%" id="flag"><img src="https://www.countryflags.io/{{country}}/shiny/48.png" onerror="this.style.display='none'"/></span>
                <span ng-click="display()" ng-if="bool=='true'"><p class="temp">{{tempC}}<span><sup ng-if='tempC!=""' id="deg">&#8451;</sup></span></p></span>
                <span ng-click="display()" ng-if="bool=='false'"><p class="temp">{{tempF}}<span><sup ng-if='tempF!=""' id="deg">&#8457;</sup></span></p></span>
            </div>

            <div id="status">
                <p id="predict_content">Now</p>
                <img src="clear-day.svg" style="width:150px;height:150px;" ng-if="iconi=='clear-day'">
                <img src="clear-night.svg" style="width:150px;height:150px;" ng-if="iconi=='clear-night'">
                <img src="cloudy.svg" style="width:150px;height:150px;" ng-if="iconi=='cloudy'">
                <img src="fog.svg" style="width:150px;height:150px;" ng-if="iconi=='fog'">
                <img src="hail.svg" style="width:150px;height:150px;" ng-if="iconi=='hail'">
                <img src="partly-cloudy-day.svg" style="width:150px;height:150px;" ng-if="iconi=='partly-cloudy-day'">
                <img src="partly-cloudy-night.svg" style="width:150px;height:150px;" ng-if="iconi=='partly-cloudy-night'">
                <img src="rain.svg" style="width:150px;height:150px;" ng-if="iconi=='rain'">
                <img src="sleet.svg" style="width:150px;height:150px;" ng-if="iconi==='sleet'">
                <img src="snow.svg" style="width:150px;height:150px;" ng-if="iconi==='snow'">
                <img src="thunderstorm.svg" style="width:150px;height:150px;" ng-if="iconi==='thunderstorm'">
                <img src="tornado.svg" style="width:150px;height:150px;" ng-if="iconi==='tornado'">
                <img src="wind.svg" style="width:150px;height:150px;" ng-if="iconi==='wind'">
                <p >{{summary}}</p>
            </div>
            <div id="humidity" style="margin-right: 10%;">
                <p id="predict_content">Humidity</p>
                <div><img src="humidity.svg" style="width:150px;height:150px;"></div>
                <p >{{humidity}} %</p>
            </div>

            <div id="pressure" style="margin-left: 10%;">
                <p id="predict_content">Wind speed</p>
                <div><img src="pressure.svg" style="width:150px;height:150px;" ></div>
                <p >{{wind}} km/hr</p>
            </div>

            <div id="predict">
                <p >{{predict}}</p>
            </div>


            <p id="error">{{error}}</p>
        </div>
    </div>

</div>

<div style="text-align: center; font-size: 15px; font-family: 'ABeeZee', sans-serif;margin-top: 30vh; margin-bottom: 30px; color: white; text-decoration: none;">
    <h3>&lt;&gt; with &#10084;</h3>
    <p style="text-align: center; font-size: 15px; font-family: 'ABeeZee', sans-serif; color: white; text-decoration: none;"> by </p>
    <a style="text-align: center; font-size: 15px; font-family: 'ABeeZee', sans-serif; color: white; text-decoration: none;" href="https://github.com/nikhils4">nikhils4</a>
    <a style="text-align: center; font-size: 15px; font-family: 'ABeeZee', sans-serif; color: white; text-decoration: none;" href="https://github.com/pm-sharma">pm-sharma</a>
    <a style="text-align: center; font-size: 15px; font-family: 'ABeeZee', sans-serif; color: white; text-decoration: none;" href="https://github.com/satin-04">satin-04</a>

</div>
</body>
</html>











