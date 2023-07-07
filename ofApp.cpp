#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	ofSetBackgroundColor(ofColor::black);

	fuente_texto.load("CormorantGaramond-Medium.ttf", 20);

	b_menu = true;
	b_p_principal = false;
	escena_esc = false;
	escena_mod = false;
	escena_ric = false;

	escalaX = ofGetScreenWidth() / ancho;
	escalaY = ofGetScreenHeight() / alto;

	pos_dialogos.y = alto * 0.96;

	linea = 0;


	abierto_p1 = true;
	abierto_p2 = true;
	abierto_p3 = true;

	cerrado = "[CERRADO]";
	mostrar_mensaje = false;
	cont_p = 0;



	//MENU--------------------------------------------------------------------------

	titulo.load("titulo.png");
	titulo_pos.x = ancho / 2 - titulo.getWidth() / 2;
	titulo_pos.y = alto / 2 - titulo.getHeight() / 2;

	empezar = u8"-Empezar-";
	empezar_pos.x = ancho / 2 - fuente_texto.stringWidth(empezar) / 2;
	empezar_pos.y = alto * 0.6;

	datos = u8"Por Ailen Ortiz y Brisa León";
	datos_pos.x = ancho / 2 - fuente_texto.stringWidth(datos) / 2;
	datos_pos.y = alto * 0.4;





	//PANTALLA PRINCIPAL------------------------------------------------------------

	amb_principal.load("amb_principal.mp3");
	amb_principal.setLoop(true);

	amb_principal.play();


	p_moda.load("p_moda.png");
	p_moda_pos.x = ofGetWidth()*0.35;
	p_moda_pos.y = ofGetHeight()*0.4;
	risa.load("risa.mp3");

	//Dialogos de la personificación de la moda
	p_moda_dialogo_principio[0] = "Hola...";
	p_moda_dialogo_principio[1] = u8"¡Sean bienvenidos a mi glamuroso mundo!";
	p_moda_dialogo_principio[2] = u8"Camino sinuoso y para nada fácil...";
	p_moda_dialogo_principio[3] = u8"... pero te garantizo que la recompensa valdrá la pena.";
	p_moda_dialogo_principio[4] = u8"¿Quiéres echar un vistazo?";

	p_moda_dialogo_final[0] = u8"Alucinante, ¿verdad?";
	p_moda_dialogo_final[1] = u8"Te dije que era un camino sacrificado.";
	p_moda_dialogo_final[2] = u8"Pero es el sacrificio el que cria a la belleza";
	p_moda_dialogo_final[3] = u8"¿Qué decís? ¿Te quedas?";
	p_moda_dialogo_final[4] = u8"Sabes, puedo notar un poco de mí, en tí...";


	
	fondo_mod[0].load("escenario_mod.png");
	fondo_mod[1].load("escenario_mod_mal.png");

	fondo_ric.load("escenario_ric.png");


	for (int i = 0; i < 3; i++)
	{
		puertas[i].load("puerta.png");
		puertas_pos[i].y = ofGetHeight()*0.13;
	}


	puertas_pos[0].x = ofGetWidth()*0.15;
	puertas_pos[1].x = ofGetWidth()*0.55;
	puertas_pos[2].x = ofGetWidth()*0.97;

	hablar = true;


	


	//ESCENA ESCLAVOS------------------------------------------------------------------------

	amb_esc.load("amb_esclavos.mp3");
	amb_esc.setLoop(true);

	amb_esc.play();
	amb_esc.setVolume(0);

	fondo_esc.load("escenario_esc.png");

	radio.load("radio.png");
	radio_pos.x = ancho * 0.12;
	radio_pos.y = alto * 0.5;

	radio_mus.load("radio.mp3");
	bandera_radio = true;
	volumen = 0;


	maq_cocer.load("maquina_cocer.png");
	maq_cocer_pos.x = ancho * 0.49 ;
	maq_cocer_pos.y = alto * 0.09;

	maq_grito.load("maquina_grito.wav");



	for (int j = 0; j < 3; j++)
	{
		esclavo[j].load("esclavo" + to_string(j) + ".png");
		esclavo_pos[j].y = alto * 0.18;
	}


	esclavo_pos[0].x = ancho * 0.105;
	esclavo_pos[1].x = ancho * 0.41;
	esclavo_pos[2].x = ancho * 0.71;


	dialogo_esc = ".................";


	dialogo_esc_miedo[0] = "Oh, no. No, no, NO, NOO ";
	dialogo_esc_miedo[1] = u8"¿¡QUÉ HICISTE!? ¡LA ROMPISTE!";
	dialogo_esc_miedo[2] = u8"¡VAN A VENIR!.. ya los escucho";
	dialogo_esc_miedo[3] = u8"¡¡¡VETE DE AQUÍ!!!";


	nino.load("nino.png");
	nino_pos.x = ancho * 0.165;
	nino_pos.y = alto * 0.83;
	dialogo_nino[0] = "Shhhhh";
	dialogo_nino[1] = u8"Estoy jugando a las escondidas con mi mamá";


	hablando_esc = false;
	hablando_miedo = false;
	hablando_nino = false;





	//ESCENA MODELOS-----------------------------------------------------------------------

	amb_mod.load("amb_modelos.mp3");
	amb_mod.setLoop(true);

	amb_mod_mal.load("amb_modelos_mal.mp3");
	amb_mod_mal.setLoop(true);


	amb_mod.play();
	amb_mod.setVolume(0);
	amb_mod_mal.play();
	amb_mod_mal.setVolume(0);


	tablet[0].load("tablet.png");
	tablet[1].load("tablet_mal.png");
	tablet_pos.x = ancho * 0.04;
	tablet_pos.y = alto * 0.58;


	tablet_video.load("tablet_video.mp4");
	tablet_video_pos.x = ancho * 0.045;
	tablet_video_pos.y = alto * 0.59;

	reproduciendo_tablet = false;



	for (int k = 0; k < 6; k++)
	{
		modelo[k][0].load("modelo" + to_string(k) + ".png");
	}

	for (int kk = 0; kk < 6; kk++)
	{
		modelo[kk][1].load("modelo" + to_string(kk) + "_mal.png");
	}


	modelo_pos[0].x = ancho * 0.1;
	modelo_pos[0].y = alto * 0.11;

	modelo_pos[1].x = ancho * 0.2;
	modelo_pos[1].y = alto * 0.11;

	modelo_pos[2].x = ancho * 0.6;
	modelo_pos[2].y = alto * 0.11;

	modelo_pos[3].x = ancho * 0.7;
	modelo_pos[3].y = alto * 0.11;

	modelo_pos[4].x = ancho * 0.3;
	modelo_pos[4].y = alto * 0.08;

	modelo_pos[5].x = ancho * 0.45;
	modelo_pos[5].y = alto * 0.08;



	frases_mod[0] = u8"Estoy haciendo la dieta de la luna";
	frases_mod[1] = u8"¡No!¡Eso tiene carbohidratos!";
	frases_mod[2] = u8"Lo siento, solo para bonitas";
	frases_mod[3] = u8"¿Nos vemos en el after party?";
	frases_mod[4] = u8"¿Cómo pudiste pasar con esas caderas por la puerta?";
	frases_mod[5] = u8"Mi estilista dice que soy un diamantito";
	frases_mod[6] = u8"Aj, paparazzi, vete a otro lugar con tu camarita";

	azar = 0;


	camara[0].load("camara.png");
	camara[1].load("camara_mal.png");
	camara_pos.x = ancho / 2 - camara[0].getWidth() / 2;
	camara_pos.y = alto * 0.88;

	flash.load("flash.wav");
	flash.setMultiPlay(true);

	fotos = 0;

	mod_echar[0] = u8"AAAAARGH";
	mod_echar[1] = u8"¡SUFICIENTE, VETE DE AQUÍ!";
	mod_echar[2] = u8"¡QUE REPUGNANTE!";
	mod_echar[3] = u8"FUERA, FUERA, FUERAA";

	distorcion = false;
	hablando_mod = false;




	//ESCENAS RICOS---------------------------------------------------------------------------------
	amb_ric.load("amb_ricos.mp3");
	amb_ric.setLoop(true);

	amb_ric.play();
	amb_ric.setVolume(0);

	tv.load("tv.png");
	tv_pos.x = ancho * 0.1;
	tv_pos.y = alto * 0.05;

	tv_video.load("tv_video.mp4");
	tv_video_pos.x = ancho * 0.105;
	tv_video_pos.y = alto * 0.055;


	mesa.load("mesa.png");
	mesa_pos.x = ancho / 2 - mesa.getWidth() / 2;
	mesa_pos.y = alto * 0.70;


	for (int r = 0; r < 5; r++)
	{
		ricos[r].load("rico" + to_string(r) + ".png");
	}


	ricos_pos[0].x = 0;
	ricos_pos[0].y = alto*0.15;

	ricos_pos[1].x = ancho*0.15;
	ricos_pos[1].y = alto*0.3;

	ricos_pos[2].x = ancho*0.35;
	ricos_pos[2].y = alto*0.05;

	ricos_pos[3].x = ancho * 0.55;
	ricos_pos[3].y = alto*0.3;

	ricos_pos[4].x = ancho*0.70;
	ricos_pos[4].y = alto*0.1;


	frases_ricos[0] = u8"¿Adivinen qué? ¡Me estoy haciendo vegano!";
	frases_ricos[1] = u8"Mi buena acción del día: me asocié a Greenpeace.";
	frases_ricos[2] = u8"Que delirio. La gente cada día más loca.";
	frases_ricos[3] = u8"Ay, no, no, no querida. Sorbetes de plástico no tenemos.";
	frases_ricos[4] = u8"No puedo creer que sigan usando caballos para juntar basura. Criaturitas.";

	cuantos_ricos = 0;
	que_rico=0;


	ricos_echar[0] = u8"Disculpa...";
	ricos_echar[1] = u8"Pero, me parece que no sos parte de nosotros.";
	ricos_echar[2] = u8"Te invito a retirarte.";
	ricos_echar[3] = u8"Gracias, y hasta nunca.";
	

	hablando_rico = false;

}


//--------------------------------------------------------------
void ofApp::update() {

	ofSoundUpdate();
	tablet_video.update();
	tv_video.update();

}


//--------------------------------------------------------------
void ofApp::draw(){




	ofScale(escalaX, escalaY);

	
	if (b_menu)
	{
		menu();
	}

	else if (b_p_principal)
	{
		pantalla_principal();
	}

	else if (escena_esc)
	{
		escena_esclavos();
	}

	else if (escena_mod)
	{
		escena_modelos();
	}

	else if (escena_ric)
	{
		escenas_ricos();
	}

}





//--------------------------------------------------------------
void ofApp::menu()
{
	titulo.draw(titulo_pos);
	fuente_texto.drawString(datos, datos_pos.x, datos_pos.y);
	fuente_texto.drawString(empezar, empezar_pos.x, empezar_pos.y);
}




//--------------------------------------------------------------
void ofApp::pantalla_principal()
{

	amb_principal.setVolume(1);
	amb_ric.setVolume(0);
	amb_mod.setVolume(0);
	amb_mod_mal.setVolume(0);
	amb_esc.setVolume(0);
	radio_mus.setVolume(0);


	for (int i = 0; i < 3; i++)
	{
		puertas[i].draw(puertas_pos[i]);
	}


	p_moda.draw(p_moda_pos);


	if (cont_p == 3) { hablar = true; }


	if (hablar)
	{

		if (cont_p == 3)
		{
			pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(p_moda_dialogo_final[linea]) / 2;

			if (linea < 5)
			{
				fuente_texto.drawString(p_moda_dialogo_final[linea], pos_dialogos.x, pos_dialogos.y);
			}
		}


		else
		{
			pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(p_moda_dialogo_principio[linea]) / 2;

			if (linea < 5)
			{
				fuente_texto.drawString(p_moda_dialogo_principio[linea], pos_dialogos.x, pos_dialogos.y);
			}
		}
	}


	if (mostrar_mensaje)
	{
		pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(cerrado) / 2;
		fuente_texto.drawString(cerrado, pos_dialogos.x, pos_dialogos.y);
	}



	if (risa.getPosition() == 1)
	{
		ofExit();


	}

}




//--------------------------------------------------------------
void ofApp::escena_esclavos()
{

	amb_principal.setVolume(0);
	amb_esc.setVolume(1);

	fondo_esc.draw(0, 0);

	maq_cocer.draw(maq_cocer_pos);


	for (int j = 0; j < 3; j++)
	{
		esclavo[j].draw(esclavo_pos[j]);
	}


	radio.draw(radio_pos);
	radio_mus.setVolume(volumen);

	nino.draw(nino_pos);


	if (hablando_nino)
	{
		hablando_esc = false;

		pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(dialogo_nino[linea]) / 2;

		if (linea < 2)
		{
			fuente_texto.drawString(dialogo_nino[linea], pos_dialogos.x, pos_dialogos.y);
		}
	}

	if (hablando_esc)
	{
		hablando_nino = false;

		pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(dialogo_esc) / 2;
		fuente_texto.drawString(dialogo_esc, pos_dialogos.x, pos_dialogos.y);
	}


	if (hablando_miedo)
	{
		hablando_nino = false;
		hablando_esc = false;

		pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(dialogo_esc_miedo[linea]) / 2;

		if (linea < 4)
		{
			fuente_texto.drawString(dialogo_esc_miedo[linea], pos_dialogos.x, pos_dialogos.y);
		}
	}

}




//--------------------------------------------------------------
void ofApp::escena_modelos()
{
	amb_principal.setVolume(0);


	if (distorcion)
	{
		fondo_mod[1].draw(0, 0);
		amb_mod_mal.setVolume(1);
		amb_mod.setVolume(0);


		for (int k = 5; k > -1; k--)
		{
			modelo[k][1].draw(modelo_pos[k]);
		}


		camara[1].draw(camara_pos);

		tablet[1].draw(tablet_pos);

	}

	else
	{
		fondo_mod[0].draw(0, 0);

		amb_mod.setVolume(0.5f);
		amb_mod_mal.setVolume(0);


		for (int k = 5; k > -1; k--)
		{
			modelo[k][0].draw(modelo_pos[k]);
		}


		camara[0].draw(camara_pos);


		if (hablando_mod)
		{
			pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(frases_mod[azar]) / 2;
			fuente_texto.drawString(frases_mod[azar], pos_dialogos.x, alto*0.04);
		}

		tablet[0].draw(tablet_pos);
		tablet_video.draw(tablet_video_pos);

		if (fotos >= 6)
		{
			hablando_mod = false;

			pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(mod_echar[linea]) / 2;
			fuente_texto.drawString(mod_echar[linea], pos_dialogos.x, alto*0.04);

		}
	}
}





//--------------------------------------------------------------
void ofApp::escenas_ricos()
{
	amb_principal.setVolume(0);
	amb_ric.setVolume(1);

	fondo_ric.draw(0, 0);

	tv.draw(tv_pos);

	tv_video.draw(tv_video_pos);


	for (int r = 0; r < 5; r++)
	{
		ricos[r].draw(ricos_pos[r]);
	}


	mesa.draw(mesa_pos);


	if (hablando_rico)
	{
		pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(frases_ricos[que_rico]) / 2;
		fuente_texto.drawString(frases_ricos[que_rico], pos_dialogos.x, alto*0.03);
	}


	if (cuantos_ricos >= 10)
	{
		hablando_rico = false;

		pos_dialogos.x = ancho / 2 - fuente_texto.stringWidth(ricos_echar[linea]) / 2;
		fuente_texto.drawString(ricos_echar[linea], pos_dialogos.x, alto*0.04);

	}
}





//--------------------------------------------------------------
void ofApp::keyReleased(int key) {


	if (!b_menu)
	{
		if (key == 'x')
		{
			b_p_principal = true;
			escena_esc = false;
			escena_mod = false;
			escena_ric = false;
		}
	}


	if (escena_mod)
	{
		if (fotos < 6)
		{
			if (key == 'c')
			{
				flash.play();
				distorcion = !distorcion;
				fotos++;

			}
		}

		
	}



	if (key == OF_KEY_RIGHT)
	{
		if (b_p_principal)
		{
			if (hablar)
			{
				if (cont_p == 3)
				{
					if (linea < 4)
					{
						linea++;
					}
					else { linea = 0; risa.play(); hablar = false; cont_p = 0; }
				}

				else
				{
					if (linea < 4)
					{
						linea++;
					}
					else { linea = 0; hablar = false; }
				}

			}

			
		}



		if (escena_esc)
		{
			if (hablando_nino)
			{
				if (linea < 1)
				{
					linea++;
				}

				else { linea = 0; hablando_nino = false; }

			}

			if (hablando_esc)
			{
				hablando_esc = false;
			}

			if (hablando_miedo)
			{
				if (linea < 3)
				{
					linea++;
				}
				else { b_p_principal = true; escena_esc = false; linea = 0; hablando_miedo = false; abierto_p1 = false; cont_p++; }

			}

		}


		if (escena_mod)
		{
			if (fotos >= 6)
			{
				if (linea < 3)
				{
					linea++;
				}
				else { b_p_principal = true; escena_mod = false; linea = 0; abierto_p2 = false; cont_p++; }
			}
		}


		if (escena_ric)
		{
			if (cuantos_ricos >= 10)
			{
				if (linea < 3)
				{
					linea++;
				}
				else { b_p_principal = true; escena_ric = false; linea = 0; abierto_p3 = false; cont_p++; }
			}
		}

	}
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){



	if (b_menu)
	{
		if (x > empezar_pos.x * escalaX && x < (empezar_pos.x + fuente_texto.stringWidth(empezar))*escalaX && y < (empezar_pos.y * escalaY) && y > (empezar_pos.y*escalaY - fuente_texto.stringHeight(empezar)))
		{
			b_menu = false;
			b_p_principal = true;
		}
	}



	if (b_p_principal)
	{

		if (!hablar)
		{
			for (int i = 0; i < 3; i++)
			{
				if (x > puertas_pos[i].x*escalaX && y > puertas_pos[i].y*escalaY && y < (puertas_pos[i].y + puertas[i].getHeight())*escalaY && x < (puertas_pos[i].x + puertas[i].getWidth())*escalaX)
				{

					switch (i) {

					case 0:

						if (abierto_p1)
						{
							b_p_principal = false;
							escena_esc = true;
							mostrar_mensaje = false;
						}
						else { mostrar_mensaje = true; }

						break;
						

					case 1:
						
						if (abierto_p2)
						{
							b_p_principal = false;
							escena_mod = true;
							mostrar_mensaje = false;
						}
						else { mostrar_mensaje = true; }

						break;


					case 2:
						if (abierto_p3)
						{
							b_p_principal = false;
							escena_ric = true;
							mostrar_mensaje = false;
						}

						else { mostrar_mensaje = true; }
						
						break;

					}
				}
			}
		}


		
	}
	


	if (escena_esc)
	{
		if (x > radio_pos.x * escalaX && x < ((radio_pos.x + radio.getWidth())*escalaX) && y > radio_pos.y *escalaY && y < ((radio_pos.y + radio.getHeight())*escalaY))
		{

			if (bandera_radio) { radio_mus.play(); bandera_radio = false; }

			else  
			{
				if (radio_mus.getVolume() == 1)
				{
					radio_mus.setVolume(0);
				}

				else if (radio_mus.getVolume() == 0)
				{
					radio_mus.setVolume(1);
				}

				volumen = radio_mus.getVolume();

			}

		}


		if (x > nino_pos.x * escalaX && x < ((nino_pos.x + nino.getWidth())* escalaX) && y > nino_pos.y * escalaY && y < ((nino_pos.y + nino.getHeight())* escalaY))
		{
			hablando_nino = true;
		}


		for (int k = 0; k < 3; k++)
		{
			if (x > (esclavo_pos[k].x * escalaX) && x < (esclavo_pos[k].x + (esclavo[k].getWidth()))*escalaX && y > (esclavo_pos[k].y * escalaY) && y < (esclavo_pos[k].y + (esclavo[k].getHeight()))*escalaY)
			{
				hablando_esc = true;
			}
		}



		if (x > (maq_cocer_pos.x * escalaX) && x < (maq_cocer_pos.x + maq_cocer.getWidth())*escalaX && y >(maq_cocer_pos.y * escalaY) && y < (maq_cocer_pos.y + maq_cocer.getHeight())*escalaY)
		{
			if (!hablando_miedo)
			{
				radio_mus.stop();
				maq_grito.play();
				hablando_miedo = true;
			}
			
		}


	}


	if (escena_mod)
	{
		if (x > tablet_video_pos.x * escalaX && x < ((tablet_video_pos.x + tablet[0].getWidth())* escalaX) && y > tablet_video_pos.y * escalaY && y < ((tablet_video_pos.y + tablet[0].getHeight())* escalaY))
		{
			if (!reproduciendo_tablet)
			{
				tablet_video.play();
				reproduciendo_tablet = true;
			}

			else 
			{
				if (tablet_video.isPlaying())
				{
					tablet_video.setPaused(true);
				}
				else { tablet_video.setPaused(false); }
			}

			

		}



		for (int k = 0; k < 6; k++)
		{
			if (x > (modelo_pos[k].x + (modelo[k][0].getWidth()*0.3))*escalaX &&
				x < (modelo_pos[k].x + (modelo[k][0].getWidth()*0.75)) * escalaX &&
				y > modelo_pos[k].y * escalaY &&
				y < (modelo_pos[k].y + (modelo[k][0].getHeight()))*escalaY)
			
			{
				azar = (int)ofRandom(0,7);
				hablando_mod = true;

			}
		}



	}



	if (escena_ric)
	{
		if (x > (tv_pos.x * escalaX) && x < (tv_pos.x + tv.getWidth())*escalaX && y > (tv_pos.y * escalaY) && y < (tv_pos.y + tv.getHeight())*escalaY)
		{
				tv_video.play();
		}


		for (int r = 0; r < 5; r++)
		{
			if (x > ricos_pos[r].x * escalaX &&
				x < (ricos_pos[r].x + (ricos[r].getWidth()) * escalaX) &&
				y > ricos_pos[r].y * escalaY &&
				y < (ricos_pos[r].y + (ricos[r].getHeight())*escalaY))

			{
				que_rico = r;
				hablando_rico = true;

				cuantos_ricos++;

			}
		}

	}
}