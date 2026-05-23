/** \file Maqui.h
 *  \brief Archivo de encabezado principal de la biblioteca Maqui
 *  
 *  Contiene la clase principal Maqui para controlar el sintetizador de MIDI.
 * \author montoyamoraga
 */

#ifndef MAQUI_H
#define MAQUI_H

#include <Arduino.h>

#include "Boton.h"
#include "FrecuenciasMIDI.h"
#include "NotasMIDI.h"
#include "Perilla.h"
#include "Pantalla12x8.h"

/** \class Maqui
 *  \brief Clase principal para controlar el sintetizador Maqui
 *  
 *  Proporciona funcionalidad para enviar mensajes MIDI, cambiar canales,
 *  mostrar información en pantalla y gestionar entradas de controles.
 */
class Maqui {

    protected:
        
        /** \brief Puntero a las notas MIDI disponibles */
        NotasMIDI *notas  = nullptr;
        
        /** \brief Puntero a la pantalla LCD 12x8 */
        Pantalla12x8 *pantalla = nullptr;

        /** \brief Puntero al control perilla 0 */
        Perilla *perilla0 = nullptr;
        
        /** \brief Puntero al control perilla 1 */
        Perilla *perilla1 = nullptr;
        
        /** \brief Puntero al control perilla 2 */
        Perilla *perilla2 = nullptr;
    
    public:

        /** \brief Constructor de la clase Maqui
         *  
         *  Inicializa todos los componentes del sintetizador incluidas
         *  notas, pantalla y perillas.
         */
        Maqui();

        /** \brief Destructor de la clase Maqui
         *  
         *  Libera la memoria de todos los componentes dinámicos.
         */
        ~Maqui();

        /** \brief Valor mínimo para el canal MIDI */
        static const int canalMinimo;
        
        /** \brief Valor máximo para el canal MIDI */
        static const int canalMaximo;

        /** \brief Inicia la conexión serie y configura el sintetizador */
        void iniciar();

        /** \brief Obtiene el canal MIDI actual
         *  \return El número del canal MIDI (1-16)
         */
        int mostrarCanal();
        
        /** \brief Cambia el canal MIDI actual
         *  \param nuevoCanal Número del nuevo canal MIDI
         */
        void cambiarCanal(int nuevoCanal);

        /** \brief Envía un mensaje MIDI Note On
         *  \param nota Número de nota (0-127)
         *  \param velocidad Velocidad de la nota (0-127)
         */
        void enviarMIDINoteOn(int nota, int velocidad);
        
        /** \brief Envía un mensaje MIDI Note Off
         *  \param nota Número de nota a apagar (0-127)
         */
        void enviarMIDINoteOff(int nota);
        
        /** \brief Envía un mensaje MIDI Control Change
         *  \param control Número de control MIDI
         *  \param valor Valor del control (0-127)
         */
        void enviarMIDIControlChange(int control, int valor);

        /** \brief Canal MIDI actual */
        static int canal;
        
        /** \brief Código de estado para MIDI Note On (0x90) */
        static int noteOn;
        
        /** \brief Código de estado para MIDI Note Off (0x80) */
        static int noteOff;
        
        /** \brief Velocidad cero para apagar notas */
        static int velocidadCero;

        /** \brief Pin de Arduino para la perilla 0 */
        static int patitaPerilla0;
        
        /** \brief Pin de Arduino para la perilla 1 */
        static int patitaPerilla1;
        
        /** \brief Pin de Arduino para la perilla 2 */
        static int patitaPerilla2;

};

#endif
